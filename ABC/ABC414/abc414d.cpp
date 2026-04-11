// https://atcoder.jp/contests/abc414/tasks/abc414_d

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
vll X;

vll Xsort;
vll dist;
ll home;
ll ans = 0;

void solve() {
    Xsort.resize(N);
    for (ll i = 0;i < N;i++) Xsort[i] = X[i];
    sort(Xsort.begin(), Xsort.end());

    home = N;
    for (ll i = 1;i < N;i++) {
        if (Xsort[i] != Xsort[i-1]) {
            dist.push_back(Xsort[i] - Xsort[i-1]);
        }
        else home--;
    }

    sort(dist.begin(), dist.end());

    if (home - M > 0) for (ll i = 0;i < (home - M);i++) ans += dist[i];

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    X.resize(N);
    for (ll i = 0;i < N;i++) cin >> X[i];
    
    solve();
    return 0;
}