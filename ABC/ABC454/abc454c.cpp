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

void solve() {
    vb visited(N, false);
    visited[0] = true;

    queue<int> route;
    route.push(0);
    while (!route.empty()) {
        int now = route.front();
        route.pop();

        for (int i : graph[now]) {
            if (!visited[i]) {
                route.push(i);
                visited[i] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0;i < N;i++) {
        if (visited[i]) ans++;
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
        int A, B;
        cin >> A >> B;
        A--;
        B--;

        graph[A].push_back(B);
    }
    
    solve();
    return 0;
}