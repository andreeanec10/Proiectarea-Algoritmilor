import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
    static class Task {
        public final static String INPUT_FILE = "in";
        public final static String OUTPUT_FILE = "out";

        int n;
        int[] sir;

        private void readInput() {
            try {
                Scanner sc = new Scanner(new File(INPUT_FILE));
                n = sc.nextInt();
                sir = new int[n];
                for (int i = 0; i < n; i++) {
                    sir[i] = sc.nextInt();
                }
                sc.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private void writeOutput(int result) {
            try {
                PrintWriter pw = new PrintWriter(new File(OUTPUT_FILE));
                pw.printf("%d\n", result);
                pw.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private int getResult() {
            int []D = new int[n];
            for(int i = 0; i < n; i++){
                D[i] = 1;
            }
            for(int i = 0; i < n ; i++) {
                for(int j = 0; j < i; j++) {
                    if(sir[j] < sir[i]) {
                        D[i] = max(D[i], D[j] + 1);
                    }
                }
            }
            
            return D[n-1];
        }
        int max(int a, int b) {
            if(a >= b)
                return a;
            return b;
        }

        public void solve() {
            readInput();
            writeOutput(getResult());
        }
    }

    public static void main(String[] args) {
        new Task().solve();
    }
}
