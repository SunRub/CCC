/**
 * CCC '19 S5 - Triangle: The Data Structure
 * @author TRS
 */
//Include
#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <list>
#include <queue>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <regex>
//Definitions
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
#define pb push_back
#define mp make_pair
#define mt make_tuple
//Constants
#define infinity 0x3f3f3f3f
#define linfinity 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
long long answer = 0;
int n, k;
int binaryIndexedTree[3001][3001];
int a[3001][3001];

void update(int x, int y, int value) {
	for (int i = x; i < sizeof(binaryIndexedTree) / sizeof(binaryIndexedTree[0]); i += (i & -i)) {
		for (int j = y; j < sizeof(binaryIndexedTree[0]) / sizeof(int); j += (j & -j)) {
			binaryIndexedTree[i][j] = max(binaryIndexedTree[i][j], value);
		}
	}
}
int query(int x, int y) {
	int answer = 0;
	for (int i = x; i > 0; i -= (i & -i)) {
		for (int j = y; j > 0; j -= (j & -j)) {
			answer = max(answer, binaryIndexedTree[i][j]);
		}
	}
	return answer;
}
int main() {
    scanf("%i%i", &n, &k);
	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= r; c++) {
			scanf("%i", &a[r][n - c + 1]);
		}
	}
	for (int d = 0; d < n; d++) {
		for (int c = 0; c <= d; c++) {
			update(n - d + c, n - c, a[n - d + c][n - c]);
		}
		int dSubtriangle = d - k + 1;
		for (int c = 0; c <= dSubtriangle; c++) {
			answer += query(n - dSubtriangle + c, n - c);
		}
	}
	printf("%lli\n", answer);
	return 0;
}
