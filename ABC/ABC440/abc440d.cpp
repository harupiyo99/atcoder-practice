// https://atcoder.jp/contests/abc440/tasks/abc440_d

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

ll N, Q;
vll A;

void solve() {
    sort(A.begin(), A.end());
    
    vll interval(N + 2, 0);
    for (ll i = 1;i <= N + 1;i++) interval[i] = A[i] - A[i - 1] - 1;
    vll sum(N + 2, 0);
    for (ll i = 1;i <= N + 1;i++) sum[i] = sum[i - 1] + interval[i];

    while (Q > 0) {
        Q--;

        ll X, Y;
        cin >> X >> Y;

        ll l = lower_bound(A.begin(), A.end(), X) - A.begin();
        ll r = lower_bound(sum.begin(), sum.end(), sum[l] + Y - (A[l] - X)) - sum.begin();

        cout << A[r] -(sum[r] + 1 - (sum[l] + Y - (A[l] - X))) << "\n";
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    A.resize(N + 1, 0);
    for (ll i = 1;i <= N;i++) cin >> A[i];
    A.push_back(100000000000);
    
    solve();
    return 0;
}