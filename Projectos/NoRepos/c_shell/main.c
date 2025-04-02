#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 64;
#define DELIM " \t\r\n\a"

// Command Struct
typedef struct {
	char *name;		// Command Name
	char **args;	// Pointer to the list of args
	char arg_count; // Number of args
} Command;

// Function Prototypes
char *read_line(void);
int parse_line(char *line, Command *cmd);
int execute_command(Command *cmd);
void free_command(Command *cmd);

int main(int argc, char *argv[])
{
	int status = 1;
	Command cmd;

	char *line = NULL;
	while (status) {
		printf("X > ");					// Shell Prompt
		line = read_line();				// Read line
		if (parse_line(line, &cmd)) { 	// Parse the line
			// execute the command we parsed from user
			status = execute_command(&cmd);
			free_command(&cmd);
		}
	}

	free(line);

	return EXIT_SUCCESS;
}

char *read_line(void)
{
	char *line = NULL;
	size_t buffsize = 0;

	if (getline(&line, &buffsize, stdin) == -1) {
		if (feof(stdin)) {
			exit(EXIT_SUCCESS); // End of File or Cmd+C(MacOs)
		}
		perror("read_line");
		exit(EXIT_FAILURE);
	}
	return line;
}

int parse_line(char *line, Command *cmd)
{
	int buffsize = MAX_ARGS;
	int pos = 0;
	char **tokens = malloc(buffsize * sizeof(char *));
	char *token;

	if (!token) {
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL) {
		tokens[pos++] = token;
		if (pos >= buffsize) {
			buffsize += MAX_ARGS;
			tokens = realloc(tokens, buffsize * sizeof(char *));
			if (!tokens) {
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, DELIM);
	}

	tokens[pos] = NULL;
	if (pos == 0) {
		free(tokens);
		return 0;
	}

	cmd->args = tokens;
	cmd->arg_count = pos;
	cmd->name = tokens[0];

	return 1;
}

int execute_command(Command *cmd)
{
	pid_t pid;

	if (strcmp(cmd->name, "exit") == 0) return EXIT_SUCCESS;

	pid = fork(); // Create child process;
	if (pid == -1) {
		fprintf(stderr, "fork() failed\n");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) execvp(cmd->name, cmd->args);

	// wait for the child process to finins
	// waitpid() cleans up child process
	// otherwise it becomes a zombie!

	int status;
	do {
		(void)waitpid(pid, &status, WUNTRACED);

	} while (!WIFEXITED(status) && !WIFSIGNALED(status));

	return EXIT_FAILURE;
}

void free_command(Command *cmd) { free(cmd->args); }
