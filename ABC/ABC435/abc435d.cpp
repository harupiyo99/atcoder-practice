#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>; 
using vvll = vector<vector<ll>>;
using vs = vector<string>;

using pii = pair<int, int>;
using pis = pair<int, string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using msi = map<string, int>;

void dfs(ll x, vector<bool>& ans, const vvll& graph) {
    for (ll i : graph[x]) {
        if (ans[i]) continue;
        else {
            ans[i] = true;
            dfs(i, ans, graph);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N,M;
    cin >> N >> M;
    vll X(M), Y(M);
    vvll graph(N);
    for (ll i = 0;i < M;i++) {
        cin >> X[i] >> Y[i];
        X[i]--;
        Y[i]--;
        graph[Y[i]].push_back(X[i]);
    }

    vector<bool> ans(N, false);

    int Q;
    cin >> Q;
    for (int i = 0;i < Q;i++) {
        int num, v;
        cin >> num >> v;
        v--;
        if (num == 1 && !ans[v]) {
            ans[v] = true;
            dfs(v, ans, graph);
        }
        else if (num == 2) {
            if (ans[v]) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}