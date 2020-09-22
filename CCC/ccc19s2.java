import java.util.*;
import java.io.*;
/**
 * CCC '19 S2 - Pretty Average Primes
 * @author TRS
 */
public class ccc19s2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int t = readInt();
		for (int i = 0; i < t; i++) {
			int n = readInt();
			if (isPrime(n)) {
				System.out.println(n + " " + n);
			}
			else {
				int l;
				int r;
				if (n % 2 == 0) {
					l = n + 1;
					r = n - 1;
				}
				else {
					l = n;
					r = n;
				}
				while (true) {
					l -= 2;
					r += 2;
					if (isPrime(l) && isPrime(r)) {
						System.out.println(l + " " + r);
						break;
					}
				}
			}
		}
	}
	static boolean isPrime(int number) {
		if (number == 2) {
			return true;
		}
		if (number % 2 == 0) {
			return false;
		}
		for (int f = 3; f < Math.sqrt(number) + 1; f += 2) {
			if (number % f == 0) {
				return false;
			}
		}
		return true;
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
