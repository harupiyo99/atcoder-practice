// https://atcoder.jp/contests/abc396/tasks/abc396_d

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

// 変数の宣言
ll N, M;
vector<vector<pll>> graph;
vll w;
vb visited;
ll ans = 2e18;

void dfs(ll x, ll curxor) {
    if (x == N-1) {
        ans = min(ans, curxor);
        return;
    }

    visited[x] = true;

    for (pll i : graph[x]) if (!visited[i.first]) dfs(i.first, curxor^i.second);

    visited[x] = false;
    return;
}

void solve() {
    dfs(0, 0);

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    
    graph.resize(N);
    w.resize(M);
    for (ll i = 0;i < M;i++) {
        ll u,v;
        cin >> u >> v >> w[i];
        u--;
        v--;
        graph[u].push_back({v, w[i]});
        graph[v].push_back({u, w[i]});
    }

    visited.assign(N, false);

    solve();
    return 0;
}
