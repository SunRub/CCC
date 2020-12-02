/**
 * DMOPC '18 Contest 6 P3 - Wish Upon a Star
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
using ull = unsigned long long;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
#define pb push_back
#define mp make_pair
#define mt make_tuple
//Constants
#define infinity 0x3f3f3f3f
#define linfinity 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
const int MX = 200001;
int N, M;
int p[MX];
int cnt = 0;
int Find(int d) {
    return p[d] == d ? p[d] : p[d] = Find(p[d]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    for (int i = 1; i <= N; i++) {
        p[i] = i;
    }
    for (int i = 1, u, v; i <= M; i++) {
        cin>>u>>v;
        int u0 = Find(u);
        int v0 = Find(v);
        if (u0 != v0) {
            p[u0] = v0;
        }
        else {
            cnt++;
        }
    }
    if (cnt <= 1) {
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }
    return 0;
}
