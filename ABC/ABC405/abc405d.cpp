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

const char u = '^', d = 'v', r = '>', l = '<';
ll H, W;
vs S;

queue<pll> memo;
vvb visited;
vector<vector<char>> ans;

void solve() {
    while (!memo.empty()) {
        ll x = memo.front().first, y = memo.front().second;
        memo.pop();

        if (x != H-1 && S[x + 1][y] != '#' && S[x + 1][y] != 'E' && !visited[x + 1][y]) {
            memo.push({x + 1, y});
            ans[x + 1][y] = u;
            visited[x + 1][y] = true;
        }
        if (y != W-1 && S[x][y + 1] != '#' && S[x][y + 1] != 'E' && !visited[x][y + 1]) {
            memo.push({x, y + 1});
            ans[x][y + 1] = l;
            visited[x][y + 1] = true;
        }
        if (x != 0 && S[x - 1][y] != '#' && S[x - 1][y] != 'E' && !visited[x - 1][y]) {
            memo.push({x - 1, y});
            ans[x - 1][y] = d;
            visited[x - 1][y] = true;
        }
        if (y != 0 && S[x][y - 1] != '#' && S[x][y - 1] != 'E' && !visited[x][y - 1]) {
            memo.push({x, y - 1});
            ans[x][y - 1] = r;
            visited[x][y - 1] = true;
        }
    }

    for (ll i = 0;i < H;i++) {
        for (ll j = 0;j < W;j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    S.resize(H);
    for (ll i = 0;i < H;i++) {
        cin >> S[i];
    }
    
    visited.assign(H, vb(W, false));
    ans.assign(H, vector<char>(W, '#'));

    for (ll i = 0;i < H;i++) for (ll j = 0;j < W;j++) if (S[i][j] == 'E') {
        memo.push({i, j});
        ans[i][j] = 'E';
    }

    solve();
    return 0;
}