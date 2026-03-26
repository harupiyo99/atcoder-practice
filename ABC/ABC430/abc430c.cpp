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
    
    ll N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    ll anum = 0, bnum = 0;
    vll suma(N+1, 0), sumb(N+1, 0);

    for (ll i = 0;i < N;i++) {
        if (S[i] == 'a') {
            anum++;
            suma[i+1] = suma[i] + 1;
            sumb[i+1] = sumb[i];
        }
        else {
            bnum++;
            sumb[i+1] = sumb[i] + 1;
            suma[i+1] = suma[i];
        }
    }

    ll ans = 0;
    for (ll i = 0;i < N;i++) {
        auto ita = lower_bound(suma.begin(), suma.end(), suma[i] + A);
        if (ita == suma.end()) continue;
        int l = distance(suma.begin(), ita);
        auto itb = lower_bound(sumb.begin(), sumb.end(), sumb[i] + B);
        int r = distance(sumb.begin(), itb) - 1;

        if (l <= r) {
            ans += r-l+1;
        }
    }

    cout << ans << "\n";
    return 0;
}