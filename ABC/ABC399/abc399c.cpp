// https://atcoder.jp/contests/abc399/tasks/abc399_c

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

ll N, M;
vector<vector<pll>> graph;

vb visited;
ll ans;

void solve(ll x) {
    queue<pll> route;
    vb rem(M, false);

    visited[x] = true;
    for (pll i : graph[x]) {
        route.push({i.first, x});
        visited[i.first] = true;
    }

    while (!route.empty()) {
        ll now = route.front().first;
        ll pre = route.front().second;
        route.pop();

        for (pll i : graph[now]) {
            if (!visited[i.first]) {
                route.push({i.first, now});
                visited[i.first] = true;
            }
            else {
                if (i.first != pre && !rem[i.second]) {
                    ans++;
                    rem[i.second] = true;
                }
            }
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    graph.resize(N);
    for (ll i = 0;i < M;i++) {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;

        graph[u].push_back({v, i});
        graph[v].push_back({u, i});
    }
    
    visited.assign(N, false);
    ans = 0;

    for (ll i = 0;i < N;i++) if (!visited[i]) solve(i);

    cout << ans << "\n";
    return 0;
}