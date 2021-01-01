import java.util.*;
import java.io.*;
/**
 * CCC '20 S1 - Surmising a Sprinter's Speed
 * @author TRS
 */
public class ccc20s1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt();
		int[][] details = new int[n][2];
		for (int i = 0; i < n; i++) {
			details[i][0] = readInt();
			details[i][1] = readInt();
		}
		Arrays.sort(details, new Comparator<int[]>() {
		    public int compare(int[] a, int[] b) {
		        return Integer.compare(a[0], b[0]);
		    }
		});
		double fast = Math.abs((double)(details[1][1] - details[0][1])/(double)(details[1][0] - details[0][0]));
		for (int i = 2; i < n; i++) {
			if (fast < Math.abs((double)(details[i][1] - details[i - 1][1])/(double)(details[i][0] - details[i - 1][0]))) {
				fast = Math.abs((double)(details[i][1] - details[i - 1][1])/(double)(details[i][0] - details[i - 1][0]));
			}
		}
		System.out.println(fast);
	}
	
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) 
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}
	static long readLong() throws IOException {
		return Long.parseLong(next());
	}
	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}
	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}
	static char readCharacter() throws IOException {
		return next().charAt(0);
	}
	static String readLine() throws IOException {
		return br.readLine().trim();
	}
}
