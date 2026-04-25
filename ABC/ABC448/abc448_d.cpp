// https://atcoder.jp/contests/abc448/tasks/abc448_d

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

ll N;
vll A;
vvll graph;
set<ll> S;

vb ans;

void dfs(ll x, ll p, ll cnt, set<ll>& S) {
    if (cnt != 0) ans[x] = true;

    for (ll i : graph[x]) {
        if (i == p) continue;
        bool check = false;

        if (!S.count(A[i])) {
            S.insert(A[i]);
            check = true;
        }
        else {
            cnt++;
        }

        dfs(i, x, cnt, S);

        if (check) S.erase(A[i]);
        else cnt--;
    }

    return;
}

void solve() {
    S.insert(A[0]);
    
    ans.assign(N, false);

    dfs(0, 0, 0, S);

    for (ll i = 0;i < N;i++) {
        if (ans[i]) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    for (ll i = 0;i < N;i++) cin >> A[i];
    graph.resize(N);
    for (ll i = 0;i < N - 1;i++) {
        ll U, V;
        cin >> U >> V;
        U--; V--;

        graph[U].push_back(V);
        graph[V].push_back(U);
    }
    
    solve();
    return 0;
}