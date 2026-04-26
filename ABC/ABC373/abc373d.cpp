// https://atcoder.jp/contests/abc373/tasks/abc373_d

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

ll N, M;
vector<vector<pll>> graph1, graph2;

vll ans;
vb visited;

void search(ll x) {
    ans[x] = 0;
    visited[x] = true;
    queue<ll> next;
    next.push(x);

    while (!next.empty()) {
        ll cur = next.front();
        next.pop();

        for (pll i : graph1[cur]) {
            if (!visited[i.first]) {
                ans[i.first] = ans[cur] + i.second;
                visited[i.first] = true;
                next.push(i.first);
            }
        }
        for (pll i : graph2[cur]) {
            if (!visited[i.first]) {
                ans[i.first] = ans[cur] - i.second;
                visited[i.first] = true;
                next.push(i.first);
            }
        }
    }

    return;
}

void solve() {
    ans.assign(N, -1);
    visited.assign(N, false);

    for (ll i = 0;i < N;i++) if (!visited[i]) {
        search(i);
    }

    for (ll i = 0;i < N;i++) cout << ans[i] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    graph1.resize(N);
    graph2.resize(N);
    for (ll i = 0;i < M;i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        graph1[u].push_back({v, w});
        graph2[v].push_back({u, w});
    } 

    solve();
    return 0;
}