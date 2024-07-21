# Example MIPS Assembly Program

.data
    prompt: .asciiz "El resultado es: "

.text
.globl main

main:
    # Load immediate values into registers
    li $t0, 10     # Load 10 into register $t0
    li $t1, 20     # Load 20 into register $t1

    # Perform addition
    addi $t0, $t0, 10
    add $t2, $t0, $t1  # Add $t0 and $t1, store the result in $t2

    # Print the result
    li $v0, 4        # Load the system call code for print_string
    la $a0, prompt   # Load address of prompt message
    syscall          # Make the system call

    li $v0, 1        # Load the system call code for print_int
    move $a0, $t2    # Move the result to $a0
    syscall          # Make the system call

    li $v0, 11
    li $a0, '\n'
    syscall

    # Exit program
    li $v0, 10       # Load the system call code for exit
    syscall          # Make the system call
