/**
 * DMOPC '15 Contest 6 P5 - A Classic Problem
 * @author TRS
 */
//Include
#include <bits/stdc++.h>
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
typedef vector<pii> vpii;
#define pb push_back
#define mp make_pair
#define mt make_tuple
//Constants
#define infinity 0x3f3f3f3f
#define linfinity 0x3f3f3f3f3f3f3f3f
#define MOD 1000000007
const int MX = 3000001;
int n, k;
int a[MX];
deque<pii> minimumQ, maximumQ;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }
    ll answer = 0;
    int index = 1;
    for (int i = 1; i <= n; i++) {
        while (!minimumQ.empty() && minimumQ.back().first >= a[i]) {
            minimumQ.pop_back();
        }
        minimumQ.pb({a[i], i});
        while (!maximumQ.empty() && maximumQ.back().first <= a[i]) {
            maximumQ.pop_back();
        }
        maximumQ.pb({a[i], i});
        while (!minimumQ.empty() && !maximumQ.empty() && maximumQ.front().first - minimumQ.front().first > k) {
            index = min(maximumQ.front().second + 1, minimumQ.front().second + 1);
            while (!minimumQ.empty() && minimumQ.front().second < index) {
                minimumQ.pop_front();
            }
            while (!maximumQ.empty() && maximumQ.front().second < index) {
                maximumQ.pop_front();
            }
        }
        answer += i - index + 1;
    }
    cout<<answer<<"\n";
    return 0;
}
