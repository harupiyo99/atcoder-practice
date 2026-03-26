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
using vs = vector<string>;

using pii = pair<int, int>;
using pis = pair<int, string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll T;
    cin >> T;
    while (T > 0) {
        T--;

        ll a, b, c;
        cin >> a >> b >> c;

        ll ans, lim, sur;
        if (a > c) {
            lim = c;
            sur = a - c;
        }
        else if (a < c) {
            lim = a;
            sur = c - a;
        }
        else {
            lim = a;
            sur = 0;
        }

        if (sur + b >= lim) ans = lim;
        else {
            ll x;
            x = (lim - sur - b) / 3;
            if ((lim - sur - b) % 3 == 2) ans = sur + b + 2 * x + 1;
            else ans = sur + b + 2 * x;
        }

        cout << ans << "\n";
    }
    return 0;
}