// https://atcoder.jp/contests/abc410/tasks/abc410_d

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

int N, M;
vector<vector<pii>> graph;
vector<vb> dp;

void solve() {
    dp.assign(N, vb(1024, false));
    queue<pii> route;
    route.push({0, 0});
    dp[0][0] = true; 

    while (!route.empty()) {
        int x = route.front().first;
        int weight = route.front().second;
        route.pop();

        for (pii i : graph[x]) {
            int next = i.first;
            int cost = i.second;

            if (!dp[next][cost ^ weight]) {
                dp[next][cost ^ weight] = true;
                route.push({next, cost ^ weight});
            }
        }
    }

    int ans = -1;
    rep(i, 1024) if (dp[N - 1][i]) {
        ans = i;
        break;
    }

    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;
    graph.resize(N);
    while (M > 0) {
        M--;

        int A, B, W;
        cin >> A >> B >> W;
        A--; B--;

        graph[A].push_back({B, W});
    }
    solve();
    return 0;
}