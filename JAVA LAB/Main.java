import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new FileReader("data.txt"));
            List<String[]> rows = new ArrayList<>();
            String line;

            // Read and split each line into columns
            while ((line = br.readLine()) != null) {
                rows.add(line.trim().split("\\s+"));
            }
            br.close();

            // Find max width for each column to align the table
            int cols = rows.get(0).length;
            int[] width = new int[cols];
            for (String[] r : rows) {
                for (int i = 0; i < cols; i++) {
                    width[i] = Math.max(width[i], r[i].length());
                }
            }

            // Print the data in table format
            for (String[] r : rows) {
                for (int i = 0; i < cols; i++) {
                    System.out.printf("%-" + (width[i] + 3) + "s", r[i]);
                }
                System.out.println();
            }

        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
