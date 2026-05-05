// https://atcoder.jp/contests/abc425/tasks/abc425_d

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

int H, W;
vector<vector<char>> S;

queue<pair<pii, ll>> masu;
vvi memo;
vvi cnt;

void solve() {
    ll cur = 0;
    cnt.resize(H, vi(W, 0));

    while (!masu.empty()) {
        ll x = masu.front().first.first;
        ll y = masu.front().first.second;
        ll c = masu.front().second;
        masu.pop();

        if (S[x][y] == '.' || S[x][y] == '#') S[x][y] = '#';
        else continue;

        if (x != 0 && S[x - 1][y] != '#') {
            memo[x - 1][y]++;
            if (memo[x - 1][y] == 1) {
                masu.push({{x - 1, y}, c + 1});
                cnt[x - 1][y] = c + 1;
            }
            else if (cnt[x - 1][y] == c && memo[x - 1][y] == 2) memo[x - 1][y] = 1;
            else S[x - 1][y] = 'w';
        }
        if (y != 0 && S[x][y - 1] != '#') {
            memo[x][y - 1]++;
            if (memo[x][y - 1] == 1) {
                masu.push({{x, y - 1}, c + 1});
                cnt[x][y - 1] = c + 1;
            }
            else if (cnt[x][y - 1] == c && memo[x][y - 1] == 2) memo[x][y - 1] = 1;
            else S[x][y - 1] = 'w';
        }
        if (x != H - 1 && S[x + 1][y] != '#') {
            memo[x + 1][y]++;
            if (memo[x + 1][y] == 1) {
                masu.push({{x + 1, y}, c + 1});
                cnt[x + 1][y] = c + 1;
            }
            else if (cnt[x + 1][y] == c && memo[x + 1][y] == 2) memo[x + 1][y] = 1;
            else S[x + 1][y] = 'w';
        }
        if (y != W - 1 && S[x][y + 1] != '#') {
            memo[x][y + 1]++;
            if (memo[x][y + 1] == 1) {
                masu.push({{x, y + 1}, c + 1});
                cnt[x][y + 1] = c + 1;
            }
            else if (cnt[x][y + 1] == c && memo[x][y + 1] == 2) memo[x][y + 1] = 1;
            else S[x][y + 1] = 'w';
        }
    }

    ll ans = 0;
    for (int i = 0;i < H;i++) for (int j = 0;j < W;j++) if (S[i][j] == '#') ans++;
    cout << ans << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    S.resize(H, vector<char>(W));
    memo.assign(H, vi(W, 0));
    for (int i = 0;i < H;i++) for (int j = 0;j < W;j++) {
        cin >> S[i][j];
        if (S[i][j] == '#') {
            masu.push({{i, j}, 0});
            memo[i][j]++;
        }
    }
    
    solve();
    return 0;
}