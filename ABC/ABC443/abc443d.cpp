// https://atcoder.jp/contests/abc443/tasks/abc443_d

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

int T;

void solve() {
    int N;
    cin >> N;
    vi R(N), Rcopy(N);
    rep(i, N) {
        cin >> R[i];
        Rcopy[i] = R[i];
    }

    for (int i = 1;i < N;i++) R[i] = min(R[i], R[i - 1] + 1);
    for (int i = N - 2;i >= 0;i--) R[i] = min(R[i], R[i + 1] + 1);

    ll ans = 0;
    for (int i = 0;i < N;i++) ans += Rcopy[i] - R[i];

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    
    while (T > 0) {
        T--;

        solve();
    }
    return 0;
}