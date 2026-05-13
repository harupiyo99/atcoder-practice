// https://atcoder.jp/contests/abc400/tasks/abc400_d

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
int A, B, C, D;

void solve() {
    vvi shooted(H, vi(W, 1e7));
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> route;
    int ans = 1e7;

    shooted[A][B] = 0;
    route.push({0, {A, B}});

    while (!route.empty()) {
        int x = route.top().second.first;
        int y = route.top().second.second;
        int shoot = route.top().first;

        if (x == C && y == D) {
            ans = min(ans, shoot);
            route.pop();
            continue;
        }
        if (shoot > shooted[x][y]) {
            route.pop();
            continue;
        }
        route.pop();

        vi dx = {x + 1, x - 1, x, x}, dy = {y, y, y + 1, y - 1};
        vi ddx = {x + 2, x - 2, x, x}, ddy = {y, y, y + 2, y - 2};

        rep(i, 4) {
            if (dx[i] < 0 || dx[i] >= H || dy[i] < 0 || dy[i] >= W) continue;

            if (S[dx[i]][dy[i]] == '.') {
                if (shoot < shooted[dx[i]][dy[i]]) {
                    shooted[dx[i]][dy[i]] = shoot;
                    route.push({shoot, {dx[i], dy[i]}});
                }
            }
            else if (S[dx[i]][dy[i]] == '#') {
                // 1マス先（壁）をコスト+1で更新
                if (shoot + 1 < shooted[dx[i]][dy[i]]) {
                    shooted[dx[i]][dy[i]] = shoot + 1;
                    route.push({shoot + 1, {dx[i], dy[i]}});
                }
                
                // 「1マス目が壁だった場合のみ」、さらにその奥もコスト1でいける
                if (ddx[i] >= 0 && ddx[i] < H && ddy[i] >= 0 && ddy[i] < W) {
                    if (shoot + 1 < shooted[ddx[i]][ddy[i]]) {
                        shooted[ddx[i]][ddy[i]] = shoot + 1;
                        route.push({shoot + 1, {ddx[i], ddy[i]}});
                    }
                }
            }
        }
    }

    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    S.resize(H, vector<char>(W));
    rep(i, H) rep(j, W) cin >> S[i][j];

    cin >> A >> B >> C >> D;
    A--; B--; C--; D--;

    solve();
    return 0;
}