// https://atcoder.jp/contests/abc415/tasks/abc415_d

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

void solve() {
    ll N, M;
    cin >> N >> M;
    vll A(M), B(M);
    for (ll i = 0;i < M;i++) cin >> A[i] >> B[i];

    vector<pll> memo(M);
    for (ll i = 0;i < M;i++) memo[i] = {A[i] - B[i], A[i]};

    sort(memo.begin(), memo.end());

    ll ans = 0, bottle = N;
    for (ll i = 0;i < M;i++) {
        ll man = 0;
        if (bottle >= memo[i].second) man = max((ll)0, (bottle - memo[i].second) / memo[i].first + 1);
        bottle -= memo[i].first * man;

        ans += man;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}