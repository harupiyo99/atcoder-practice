// https://atcoder.jp/contests/abc418/tasks/abc418_d

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

int N;
string S;

void solve() {
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S;
    vi dpE(N + 1, 0), dpO(N + 1, 0);
    for (ll i = 0;i < N;i++) {
        if (S[i] == '0') {
            dpE[i + 1] = dpO[i];
            dpO[i + 1] = dpE[i] + 1;
        }
        else {
            dpE[i + 1] = dpE[i] + 1;
            dpO[i + 1] = dpO[i];
        }
    }

    ll ans = 0;
    for (ll i = 1;i <= N;i++) ans += dpE[i];
    cout << ans << "\n";
    
    solve();
    return 0;
}