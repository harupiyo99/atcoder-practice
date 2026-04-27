// https://atcoder.jp/contests/abc362/tasks/abc362_d

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
vll A;
vector<vector<pll>> graph;

void solve() {
    vll weight(N, 10000000000000000);
    priority_queue<pll, vector<pll>, greater<pll>> route;
    route.push({A[0], 0});
    weight[0] = A[0];

    while (!route.empty()) {
        ll w = route.top().first;
        ll cur = route.top().second;
        route.pop();

        if (w > weight[cur]) continue;

        for (pll i : graph[cur]) if (A[i.first] + i.second + weight[cur] < weight[i.first]) {
            weight[i.first] = A[i.first] + i.second + weight[cur];
            route.push({weight[i.first], i.first});
        }
    }

    for (ll i = 1;i < N;i++) cout << weight[i] << " ";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.resize(N);
    for (ll i = 0;i < N;i++) cin >> A[i];
    graph.resize(N);
    while (M > 0) {
        M--;

        ll U, V, B;
        cin >> U >> V >> B;
        U--; V--;

        graph[U].push_back({V, B});
        graph[V].push_back({U, B});
    }
    
    solve();
    return 0;
}