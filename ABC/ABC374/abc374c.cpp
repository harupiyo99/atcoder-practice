// https://atcoder.jp/contests/abc374/submissions/me

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

    ll N;
    cin >> N;
    vll K(N);
    for (ll i = 0;i < N;i++) cin >> K[i];

    ll ans = 10000000000;
    for (ll i = 0;i < (1 << N);i++) {
        ll num = i;
        ll A = 0, B = 0;
        for (ll j = N-1;j >= 0;j--) {
            if (num / (1 << j) == 1) {
                num -= (1 << j);
                A += K[j];
            }
            else {
                B += K[j];
            }
        }

        ans = min(ans, max(A, B));
    }

    cout << ans << "\n";
    
    return 0;
}