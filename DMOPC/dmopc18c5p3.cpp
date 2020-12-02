/**
 * DMOPC '18 Contest 5 P3 - A Familiar Problem
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
int N;
ll M;
ll C;
int Answer;
int c[MX];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>N>>M;
    Answer = 0;
    for (int i = 0; i < N; i++) {
        cin>>c[i];
    }
    ll sum = c[0];
    for (int l = 0, r = 0; r < N;) {
        if (sum < M) {
            Answer = max(Answer, r - l + 1);
            sum += c[++r];
        }
        else {
            sum -= c[l++];
            if (l > r) {
                sum += c[++r];
            }
        }
    }
    cout<<Answer<<"\n";
    return 0;
}
