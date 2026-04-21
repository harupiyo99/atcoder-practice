// https://atcoder.jp/contests/abc441/tasks/abc441_d

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

ll N, M, L, S, T;
vector<vector<pll>> graph;
vb ans;

void dfs(ll x, ll c, ll cost) {
    if (c == L - 1) {
        for (pll i : graph[x]) if (i.second + cost >= S && i.second + cost <= T) ans[i.first] = true;
    }
    else {
        for (pll i : graph[x]) dfs(i.first, c + 1, cost + i.second);
    }

    return;
}

void solve() {
    dfs(0, 0, 0);

    for (ll i = 0;i < N;i++) if (ans[i]) cout << i + 1 << " "; 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> L >> S >> T;
    graph.resize(N);
    for (ll i = 0;i < M;i++) {
        ll U, V, C;
        cin >> U >> V >> C;
        U--; V--;

        graph[U].push_back({V, C});
    }

    ans.assign(N, false);
    
    solve();
    return 0;
}