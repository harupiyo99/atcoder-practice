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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll T;
    cin >> T;
    
    for (ll j = 0;j < T;j++) {
        ll N, sumP = 0;
        cin >> N;
        vll W(N), P(N), WP(N);
        for (ll i = 0;i < N;i++) {
            cin >> W[i] >> P[i];
            WP[i] = W[i] + P[i];
            sumP += P[i];
        }

        sort(WP.begin(), WP.end());

        ll sumS = 0, ans = N;
        for (ll i = 0;i < N;i++) {
            sumS += WP[i];
            if (sumS > sumP) {
                ans = i;
                break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}