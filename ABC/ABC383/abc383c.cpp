// https://atcoder.jp/contests/abc383/tasks/abc383_c

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
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

ll H, W, D;
vector<vector<char>> S;
queue<pair<pii, ll>> memo;
vector<vb> wet;

void solve() {
    ll ans = 0;

    while (!memo.empty()) {
        ll x = memo.front().first.first;
        ll y = memo.front().first.second;
        ll t = memo.front().second;
        
        memo.pop();

        if (x != H - 1 && !wet[x + 1][y] && S[x + 1][y] != '#') {
            wet[x + 1][y] = true;
            if (t < D - 1) memo.push({{x + 1, y}, t + 1});
        }
        if (y != W - 1 && !wet[x][y + 1] && S[x][y + 1] != '#') {
            wet[x][y + 1] = true;
            if (t < D - 1) memo.push({{x, y + 1}, t + 1});
        }
        if (x != 0 && !wet[x - 1][y] && S[x - 1][y] != '#') {
            wet[x - 1][y] = true;
            if (t < D - 1) memo.push({{x - 1, y}, t + 1});
        }
        if (y != 0 && !wet[x][y - 1] && S[x][y - 1] != '#') {
            wet[x][y - 1] = true;
            if (t < D - 1) memo.push({{x, y - 1}, t + 1});
        }
    }

    for (ll i = 0;i < H;i++) for (ll j = 0;j < W;j++) if (wet[i][j]) ans++;

    cout << ans << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> D;
    S.resize(H, vector<char>(W));
    wet.resize(H, vb(W, false));

    ll count = 0;

    for (ll i = 0;i < H;i++) for (ll j = 0;j < W;j++) {
        cin >> S[i][j];

        if (S[i][j] == 'H') {
            memo.push({{i, j}, 0});
            wet[i][j] = true;
            count++;
        }
    }

    if (D == 0) cout << count << "\n";
    else solve();
    return 0;
}