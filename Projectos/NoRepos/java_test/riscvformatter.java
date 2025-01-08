import java.io.*;
import java.util.*;
import java.util.stream.Collectors;

public class riscvformatter {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.err.println("Usage: java RiscVFormatter <file>");
            System.exit(1);
        }

        File file = new File(args[0]);
        if (!file.exists() || !file.isFile()) {
            System.err.println("File not found: " + args[0]);
            System.exit(1);
        }

        try {
            List<String> lines = readLinesFromFile(file);
            System.out.println(Arrays.toString(lines.toArray())); //Debug
            List<String> formattedLines = formatLines(lines);
            writeLinesToFile(file, formattedLines);
            System.out.println("Formatting completed successfully.");
        } catch (IOException e) {
            System.err.println("Error processing the file: " + e.getMessage());
            e.printStackTrace();
        }
    }

    private static List<String> readLinesFromFile(File file) throws IOException {
        try (BufferedReader reader = new BufferedReader(new FileReader(file))) {
            return reader.lines().collect(Collectors.toList());
        }
    }

    private static void writeLinesToFile(File file, List<String> lines) throws IOException {
        try (PrintWriter writer = new PrintWriter(new FileWriter(file))) {
            for (String line : lines) {
                writer.println(line);
            }
        }
    }

    private static List<String> formatLines(List<String> lines) {
        return lines.stream()
            .map(riscvformatter::formatLine)
            .collect(Collectors.toList());
    }

    private static String formatLine(String line) {
        // Implement the logic for formatting a single line of RISC-V assembly here
        line = line.trim(); // Removes leading and trailing whitespace
        if (line.isEmpty()) {
            return line;
        }

        // Example formatting logic, adjust based on actual needs
        String[] parts = line.split("\\s+");
        if (parts.length > 0) {
            // Align the instruction and arguments, e.g., spacing adjustments
            parts[0] = String.format("%-10s", parts[0]); // Left-align the instruction
        }

        return String.join(" ", parts);
    }
}