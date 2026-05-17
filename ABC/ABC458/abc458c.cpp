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

string S;
ll N;

void solve() {
    ll ans = 0;

    rep(i, N) {
        ll c = 0;
        if (S[i] == 'C') c = min(i + 1, N - i);

        ans += c;
    }

    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    
    solve();
    return 0;
}