import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.ArrayList;

public class Main {
    static class Obj {
        public int weight;
        public int price;

        public Obj() {
            weight = 0;
            price = 0;
        }
    };

    static class Task {
        public final static String INPUT_FILE = "in";
        public final static String OUTPUT_FILE = "out";

        int n, w;
        Obj[] objs;

        private void readInput() {
            try {
                Scanner sc = new Scanner(new File(INPUT_FILE));
                n = sc.nextInt();
                w = sc.nextInt();
                objs = new Obj[n];
                for (int i = 0; i < n; i++) {
                    objs[i] = new Obj();
                    objs[i].weight = sc.nextInt();
                    objs[i].price = sc.nextInt();
                }
                sc.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private void writeOutput(double result) {
            try {
                PrintWriter pw = new PrintWriter(new File(OUTPUT_FILE));
                pw.printf("%.4f\n", result);
                pw.close();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        private int getResult() {
            // TODO: Aflati profitul maxim care se poate obtine cu
            // obiectele date.
            int [][] D = new int[n][w];
        
     
            for(int i = 1; i < n; i++) {
                for(int j = w - objs[i-1].weight; j >= 0; j--) {
                    D[i][j] = max(D[i - 1][j], D[i - 1][j]) + objs[i-1].price;
                }
            }

              System.out.println(D[n-1][0]);
            return D[n-1][1];
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
