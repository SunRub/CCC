import java.util.*;
import java.io.*;
/**
 * CCC '17 S2 - High Tide, Low Tide
 * @author TRS
 */
public class H2Q3 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int n = readInt();
		int[] m = new int[n];
		for (int l = 0; l < n; l++) {
			m[l] = readInt();
		}
		Arrays.sort(m);
		String prnt = "";
		if (n == 0) {
			
		}
		else if (n == 1) {
			System.out.println(m[0]);
		}
		else if (n == 2) {
			System.out.println(m[0] + " " + m[1]);
		}
		else if (n % 2 == 0) {
			for (int i = 0; i < m.length / 2; i++) {
				prnt += (" " + m[m.length / 2 - 1 - i] + " " + m[m.length / 2 + i]);
			}
			System.out.println(prnt.substring(1));
		}
		else {
			for (int i = 0; i < m.length / 2; i++) {
				prnt += (" " + m[m.length / 2 - i] + " " + m[m.length / 2 + 1 + i]);
			}
			System.out.println(prnt.substring(1) + " " + m[0]);
		}
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
