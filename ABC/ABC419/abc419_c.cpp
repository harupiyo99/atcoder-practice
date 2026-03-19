// https://atcoder.jp/contests/abc419/tasks/abc419_c

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>       
#include<queue>
#include<cmath>
#include<iomanip>

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
    
    ll N;
    cin >> N;
    vll R(N), C(N);
    for (ll i = 0;i < N;i++) cin >> R[i] >> C[i];

    ll Rmax = 0, Cmax = 0, Rmin = 10000000000, Cmin = 10000000000;
    for (ll i = 0;i < N;i++) {
        Rmax = max(Rmax, R[i]);
        Rmin = min(Rmin, R[i]);
        Cmax = max(Cmax, C[i]);
        Cmin = min(Cmin, C[i]);
    }

    cout << max((Rmax - (Rmax + Rmin) / 2), (Cmax - (Cmax + Cmin) / 2)) << "\n";
    return 0;
}