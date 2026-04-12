// https://atcoder.jp/contests/abc392/tasks/abc392_d

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

ll N;
vll K;
vvll A;
vector<unordered_map<ll, ll>> memo;

void solve() {
    double ans = 0;

    for (ll i = 0;i < N - 1;i++) for (ll j = i + 1;j < N;j++) {
        ll count = 0;
        for (ll k : A[i]) count += memo[j][k];

        ans = max(ans, (double)(count) / (double)(K[i] * K[j]));
    }

    cout << fixed;
    cout << setprecision(10) << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    memo.resize(N);
    K.resize(N);
    for (ll i = 0;i < N;i++) {
        cin >> K[i];

        for (ll j = 0;j < K[i];j++) {
            ll a;
            cin >> a;
            A[i].push_back(a);

            memo[i][a]++;
        }
    }
    
    solve();
    return 0;
}