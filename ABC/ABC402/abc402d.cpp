// https://atcoder.jp/contests/abc402/tasks/abc402_d

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

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

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
vll sur;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    sur.assign(N, 0);
    ll t = M;
    while (t > 0) {
        t--;

        ll A, B;
        cin >> A >> B;
        sur[(A + B + N) % N]++;
    }
    
    ll ans = 0;
    rep(i, N) ans += sur[i] * (sur[i] - 1) / 2;

    cout << M * (M - 1) / 2 - ans << "\n";
    return 0;
}