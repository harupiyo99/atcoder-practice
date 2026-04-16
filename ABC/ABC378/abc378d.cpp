// https://atcoder.jp/contests/abc378/tasks/abc378_d

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

ll H, W, K;
vector<vector<char>> S;
vector<pll> blanks;

vector<vb> visited;
ll ans = 0;

void dfs(ll x, ll y, ll c) {

    if (x != H - 1 && !visited[x + 1][y] && S[x + 1][y] != '#') {
        if (c < K - 1) {
            visited[x + 1][y] = true;
            dfs(x + 1, y, c + 1);
            visited[x + 1][y] = false;
        }
        else {
            ans++;
        }
    }
    if (y != W - 1 && !visited[x][y + 1] && S[x][y + 1] != '#') {
        if (c < K - 1) {
            visited[x][y + 1] = true;
            dfs(x, y + 1, c + 1);
            visited[x][y + 1] = false;
        }
        else {
            ans++;
        }
    }
    if (x != 0 && !visited[x - 1][y] && S[x - 1][y] != '#') {
        if (c < K - 1) {
            visited[x - 1][y] = true;
            dfs(x - 1, y, c + 1);
            visited[x - 1][y] = false;
        }
        else {
            ans++;
        }
    }
    if (y != 0 && !visited[x][y - 1] && S[x][y - 1] != '#') {
        if (c < K - 1) {
            visited[x][y - 1] = true;
            dfs(x, y - 1, c + 1);
            visited[x][y - 1] =false;
        }
        else {
            ans++;
        }
    }

    return;
}

void solve() {
    for (pll i : blanks) {
        visited.assign(H, vb(W, false));
        visited[i.first][i.second] = true;

        dfs(i.first, i.second, 0);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W >> K;
    S.resize(H, vector<char>(W));
    for (ll i = 0;i < H;i++) for (ll j = 0;j < W;j++) {
        cin >> S[i][j];
        if (S[i][j] == '.') blanks.push_back({i, j});
    }
    
    solve();
    return 0;
}