import java.util.*;
import java.io.*;
/**
 * TLE '17 Contest 5 P1 - Guess the Number
 * @author TRS
 */
public class tle17c5p1 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		System.out.println("guess 50");
		System.out.flush();
		int n = readInt();
		System.out.println("answer " + (50 - n));
	}
	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			st = new StringTokenizer(br.readLine().trim());
		}
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
