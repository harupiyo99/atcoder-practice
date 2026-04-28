// https://atcoder.jp/contests/abc436/tasks/abc436_d

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

vector<vector<pii>> memoc;
vector<vb> visited;
queue<pair<pii, int>> route;
vb check;

void solve() {
    visited.assign(H, vb(W, false));
    check.assign(26, false);
    route.push({{0, 0}, 0});
    visited[0][0] = true;

    while (!route.empty()) {
        int x = route.front().first.first;
        int y = route.front().first.second;
        int cnt = route.front().second;

        route.pop();

        if (x == H - 1 && y == W - 1) {
            if (S[x][y] != '#') {
                cout << cnt << "\n";
            }
            else cout << -1 << "\n";
            return;
        }
        
        if (S[x][y] != '.' && S[x][y] != '#') {
            if (!check[(S[x][y] - 'a')]) {
                for (pii i : memoc[S[x][y] - 'a']) if (!visited[i.first][i.second]) {
                    visited[i.first][i.second] = true;
                    route.push({{i.first, i.second}, cnt + 1});
                }
                check[(S[x][y] - 'a')] = true;
            }
        }
        vector<pii> key = {{x + 1, y}, {x, y + 1}, {x - 1, y}, {x, y - 1}};
        for (int i = 0;i < 4;i++) {
            int lin = key[i].first;
            int col = key[i].second;

            if (0 <= lin && lin < H && 0 <= col && col < W && !visited[lin][col] && S[lin][col] != '#') {
                visited[lin][col] = true;
                route.push({{lin, col}, cnt + 1});
            }
        }
    }

    cout << -1 << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    S.resize(H, vector<char>(W));
    memoc.resize(26);
    for (int i = 0;i < H;i++) for (int j = 0;j < W;j++) {
        cin >> S[i][j];

        if (S[i][j] != '#' && S[i][j] != '.') memoc[(S[i][j] - 'a')].push_back({i, j}); 
    }
    
    solve();
    return 0;
}