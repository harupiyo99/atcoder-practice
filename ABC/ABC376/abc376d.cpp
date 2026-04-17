// https://atcoder.jp/contests/abc376/tasks/abc376_d

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

int N, M;
vvi graph;

int ans;
vb visited;

void solve() {
    visited.assign(N,false);
    ans = -1;

    queue<pii> route;
    route.push({0, 0});

    while (!route.empty() && ans == -1) {
        int now = route.front().first;
        int c = route.front().second;
        route.pop();

        for (int i : graph[now]) {
            if (i == 0) {
                ans = c + 1;
                break;
            }
            else if (!visited[i]) {
                route.push({i, c + 1});
                visited[i] = true;
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
    
    cin >> N >> M;
    graph.resize(N);

    for (int i = 0;i < M;i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;

        graph[a].push_back(b);
    }
    solve();
    return 0;
}