// https://atcoder.jp/contests/abc409/tasks/abc409_c

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, L;
    cin >> N >> L;
    vll d(N-1);
    for (ll i = 0;i < N-1;i++) cin >> d[i];

    vll P(N), cir(L, 0);
    P[0] = 0, cir[0] = 1;
    for (ll i = 0;i < N-1;i++) {
        P[i+1] = (P[i] + d[i]) % L;
        cir[P[i+1]]++;
    } 
    
    ll ans = 0;
    if (L % 3 != 0) {
        cout << ans;
        return 0;
    }
    for (ll i = 0;i < L/3;i++) {
        ans += (cir[i] * cir[i + L / 3] * cir[i + (2 * L) / 3]);
    }
    cout << ans << "\n";
    return 0;
}