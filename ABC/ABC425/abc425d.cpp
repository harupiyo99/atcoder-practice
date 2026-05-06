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
    cnt.resize(H, vi(W, 0));

    while (!masu.empty()) {
        int x = masu.front().first.first;
        int y = masu.front().first.second;
        ll c = masu.front().second;
        masu.pop();

        if (S[x][y] == '.' || S[x][y] == '#') S[x][y] = '#';
        else continue;

        vi dx = {x + 1, x - 1, x, x}, dy = {y, y, y + 1, y - 1};
        
        rep(i, 4) {
            if (dx[i] < 0 || dx[i] >= H || dy[i] < 0 || dy[i] >= W) continue;

            if (S[dx[i]][dy[i]] != '#') {
                memo[dx[i]][dy[i]]++;
                if (memo[dx[i]][dy[i]] == 1) {
                    masu.push({{dx[i], dy[i]}, c + 1});
                    cnt[dx[i]][dy[i]] = c + 1;
                }
                else if (cnt[dx[i]][dy[i]] == c && memo[dx[i]][dy[i]] == 2) memo[dx[i]][dy[i]] = 1;
                else S[dx[i]][dy[i]] = 'w';
            }
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