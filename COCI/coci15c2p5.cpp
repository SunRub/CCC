/**
 * COCI '15 Contest 2 #5 Vudu
 * @author TRS
 */
//Include
#include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>
#include <list>
#include <queue>
#include <cmath>
#include <climits>
#include <vector>
#include <string>
#include <regex>
#include <iterator>
//Definitions
using namespace std;
using ll = long long;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
#define pb push_back
#define mp make_pair
#define mt make_tuple
//Constants
#define infinity 0x3f3f3f3f
#define linfinity 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
const int MX = 1000001;
int N, P;
ll Answer;
int cnt;
int bit[MX];
ll psa[MX];
ll order[MX];
void update(int index, int value) {
    for (int i = index; i <= N + 1; i += (i & -i)) {
		bit[i] += value;
	}
}
int query(int index) {
    int answer = 0;
	for (int i = index; i > 0; i -= (i & -i)) {
		answer += bit[i];
	}
	return answer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N;
    for (int i = 1; i <= N; i++) {
        cin>>psa[i];
    }
    cin>>P;
    for (int i = 1; i <= N; i++) {
        psa[i] = psa[i] - P + psa[i - 1];
        order[i] = psa[i];
    }
    sort(order, order + N + 1);
    int sz = unique(order, order + N + 1) - order;
    for (int i = 0; i <= N; i++) {
        int rnk = lower_bound(order, order + sz, psa[i]) - order + 1;
        Answer += query(rnk);
        update(rnk, 1);
    }
    cout<<Answer<<"\n";
    return 0;
}
