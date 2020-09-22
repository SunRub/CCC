import java.util.*;
import java.io.*;
/**
 * CCC '20 S2 - Escape Room
 * @author TRS
 */
public class ccc20s2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	public static void main(String[] args) throws IOException {
		int m = readInt();
		int n = readInt();
		boolean escapable = false;
		int[][] grid = new int[1001][1001];
		boolean[][] visited = new boolean[1001][1001];
		ArrayList<Cell>[] adjacent = new ArrayList[1000001];
		for (int i = 0; i < 1000001; i++) {
			adjacent[i] = new ArrayList<Cell>();
		}
		for (int row = 1; row <= m; row++) {
			for (int column = 1; column <= n; column++) {
				grid[row][column] = readInt();
				adjacent[row * column].add(new Cell(row, column));
			}
		}
		visited[1][1] = true;
		Queue<Cell> queue = new LinkedList<Cell>();
		queue.add(new Cell(1, 1));
		while (!queue.isEmpty()) {
			int cellR = queue.peek().row;
			int cellC = queue.peek().column;
			if (cellR == m && cellC == n) {
				escapable = true;
				break;
			}
			queue.remove();
			for (Cell cell : adjacent[grid[cellR][cellC]]) {
				if (cell.row <= m && cell.column <= n && !visited[cell.row][cell.column]) {
					queue.add(new Cell(cell.row, cell.column));
					visited[cell.row][cell.column] = true;
				}
			}
		}
		if (escapable) {
			System.out.println("yes");
		}
		else {
			if (visited[m][n]) {
				System.out.println("yes");
			}
			else {
				System.out.println("no");
			}
		}
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
class Cell {
	public int row;
	public int column;
	public Cell(int row, int column) {
		this.row = row;
		this.column = column;
	}
}
