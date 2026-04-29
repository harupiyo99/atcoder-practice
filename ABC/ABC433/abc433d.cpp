// https://atcoder.jp/contests/abc433/tasks/abc433_d

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

ll N, M;
vll A;

void solve() {
    vll ten(11);
    ten[0] = 1;
    for (ll i = 1;i < 11;i++) ten[i] = (ten[i - 1] * 10) % M;

    vector<unordered_map<ll, ll>> rem(11);
    for (ll i = 0;i < N;i++) for (ll j = 0;j < 11;j++) {
        rem[j][(A[i] * ten[j]) % M]++;
    }

    ll ans = 0;
    for (ll i = 0;i < N;i++) {
        string S = to_string(A[i]);
        int len = S.size();

        ans += rem[len][(M - (A[i] % M)) % M];
    }

    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.resize(N);
    for (ll i = 0;i < N;i++) cin >> A[i];
    
    solve();
    return 0;
}