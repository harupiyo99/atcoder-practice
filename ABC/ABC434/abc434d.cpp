//https://atcoder.jp/contests/abc434/tasks/abc434_d

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>; 
using vvll = vector<vector<ll>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;

using pii = pair<int, int>;
using pis = pair<int, string>;
using pll = pair<ll, ll>;
using pls = pair<ll, string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using msi = map<string, int>;

ll N;
vvll memo;
vvll popu;
vvll num;
vvll npopu;

void solve() {
    for (ll i = 1;i <= 2000;i++) for (ll j = 1;j <= 2000;j++) {
        popu[i][j] = popu[i][j - 1] + memo[i][j];
        npopu[i][j] = npopu[i][j - 1] + num[i][j];
    }
    for (ll i = 1;i <= 2000;i++) for (ll j = 1;j <= 2000;j++) {
        npopu[i][j] += npopu[i - 1][j];
        popu[i][j] += popu[i - 1][j];
    }

    ll sum = 0;
    vll van(N + 1, 0);
    for (ll i = 1;i <= 2000;i++) for (ll j = 1;j <= 2000;j++) {
        if (popu[i][j] == 0) sum++;
        if (popu[i][j] == 1) van[npopu[i][j]]++;
    }

    for (ll i = 1;i <= N;i++) cout << van[i] + sum << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    memo.assign(2002, vll(2002, 0));
    popu.assign(2002, vll(2002, 0));
    num.assign(2002, vll(2002, 0));
    npopu.assign(2002, vll(2002, 0));
    for (ll i = 1;i <= N;i++) {
        ll U, D, L, R;
        cin >> U >> D >> L >> R;

        memo[U][L]++;
        memo[U][R + 1]--;
        memo[D + 1][L]--;
        memo[D + 1][R + 1]++;

        num[U][L] += i;
        num[U][R + 1] -= i;
        num[D + 1][L] -= i;
        num[D + 1][R + 1] += i;
    }
    
    solve();
    return 0;
}