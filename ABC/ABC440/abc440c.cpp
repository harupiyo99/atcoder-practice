// https://atcoder.jp/contests/abc440/tasks/abc440_c

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
    ll N, W;
    cin >> N >> W;
    vll C(N);
    for (ll i = 0;i < N;i++) cin >> C[i];

    vll S(2 * W, 0);
    ll sum = 0;
    for (ll i = 0;i < N;i++) {
        S[i % (2 * W)] += C[i];
        if (i % (2 * W) < W) sum += C[i];
    }
    vll S2 = S;
    for (ll i : S) S2.push_back(i);

    ll ans = 10000000000000000;
    for (ll i = 0;i < 2 * W;i++) {
        sum = sum - S2[i] + S2[i + W];
        ans = min(sum, ans);
    }

    cout << ans << "\n";
    return;
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