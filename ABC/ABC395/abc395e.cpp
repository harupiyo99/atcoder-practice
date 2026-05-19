// https://atcoder.jp/contests/abc395/tasks/abc395_e

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

ll N, M, X;
vvll fgraph,igraph;

void solve() {
    priority_queue<pair<ll, pair<ll, bool>>, vector<pair<ll, pair<ll, bool>>>, greater<pair<ll, pair<ll, bool>>>> route;
    route.push({0, {0, true}});

    vvll cost(N, vll(2, 5e15));
    cost[0][1] = 0;

    while (!route.empty()) {
        ll x = route.top().second.first;
        bool state = route.top().second.second;
        if (route.top().first > cost[x][state]) {
            route.pop();
            continue;
        }
        route.pop();

        if (state) {
            for (ll f : fgraph[x]) {
                if (cost[f][1] > cost[x][1] + 1) {
                    cost[f][1] = cost[x][1] + 1;
                    route.push({cost[x][1] + 1, {f, true}});
                }
            }
            for (ll i : igraph[x]) {
                if (cost[i][0] > cost[x][1] + X + 1) {
                    route.push({cost[x][1] + X + 1, {i, false}});
                    cost[i][0] = cost[x][1] + X + 1;
                }
            }
        }
        else {
            for (ll f : fgraph[x]) {
                if (cost[f][1] > cost[x][0] + X + 1) {
                    route.push({cost[x][0] + X + 1, {f, true}});
                    cost[f][1] = cost[x][0] + X + 1;
                }
            }
            for (ll i : igraph[x]) {
                if (cost[i][0] > cost[x][0] + 1) {
                    route.push({cost[x][0] + 1, {i, false}});
                    cost[i][0] = cost[x][0] + 1;
                }
            }
        }
    }

    cout << min(cost[N - 1][0], cost[N - 1][1]) << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> X;
    fgraph.resize(N);
    igraph.resize(N);
    while (M > 0) {
        M--;

        ll u, v;
        cin >> u >> v;
        u--; v--;

        fgraph[u].push_back(v);
        igraph[v].push_back(u);
    }
    
    solve();
    return 0;
}