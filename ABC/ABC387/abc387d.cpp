// https://atcoder.jp/contests/abc387/tasks/abc387_d

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

int sx, sy, gx, gy;

void solve() {
    vector<vvi> cnt(H, vvi(W, vi(2, -1)));

    cnt[sx][sy][0] = 0; cnt[sx][sy][1] = 0;

    queue<pair<pii, bool>> route;
    route.push({{sx, sy}, true}); route.push({{sx, sy}, false});

    while (!route.empty() && cnt[gx][gy][0] == -1 && cnt[gx][gy][1] == -1) {
        int x = route.front().first.first, y = route.front().first.second;
        bool vec = route.front().second;

        route.pop();

        vi dx = {x + 1, x - 1, x, x}, dy = {y, y, y + 1, y - 1};

        if (vec) {
            for (int i = 2;i < 4;i++) {
                if (dx[i] < 0 || dx[i] >= H || dy[i] < 0 || dy[i] >= W) continue;

                if (cnt[dx[i]][dy[i]][0] == -1 && S[dx[i]][dy[i]] != '#') {
                    cnt[dx[i]][dy[i]][0] = cnt[x][y][1] + 1;

                    route.push({{dx[i], dy[i]}, false});
                }
            }
        }
        if (!vec) {
            for (int i = 0;i < 2;i++) {
                if (dx[i] < 0 || dx[i] >= H || dy[i] < 0 || dy[i] >= W) continue;

                if (cnt[dx[i]][dy[i]][1] == -1 && S[dx[i]][dy[i]] != '#') {
                    cnt[dx[i]][dy[i]][1] = cnt[x][y][0] + 1;

                    route.push({{dx[i], dy[i]}, true});
                }
            }
        }
    }

    cout << max(cnt[gx][gy][0], cnt[gx][gy][1]) << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    S.resize(H, vector<char>(W));

    rep(i, H) rep(j, W) {
        cin >> S[i][j];
        if (S[i][j] == 'S') {
            sx = i; sy = j;
        }
        if (S[i][j] == 'G') {
            gx = i; gy = j;
        }
    }
    
    solve();
    return 0;
}