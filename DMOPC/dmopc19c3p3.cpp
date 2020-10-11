/**
 * DMOPC '19 Contest 3 P3 - Majority
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
const int MX = 150001;
int n;
int psa[MX];
int bit[2*MX];
ll answer = 0;

void update(int index, int value) {
    index += n + 1;
    for (int i = index; i <= 2 * n + 1; i += (i & -i)) {
        bit[i] += value;
    }
}
int query(int index) {
    index += n + 1;
    ll sum = 0;
    for (int i = index; i > 0; i -= (i & -i)) {
        sum += bit[i];
    }
    return sum;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for (int i = 1, x; i <= n; i++) {
        cin>>x;
        psa[i] = psa[i - 1] + (x == 1 ? 1 : -1);
    }
    update(0, 1);
    for (int i = 1; i <= n; i++) {
        answer += query(psa[i] - 1);
        update(psa[i], 1);
    }
    cout<<answer<<"\n";
    return 0;
}
