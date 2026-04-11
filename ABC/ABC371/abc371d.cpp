// https://atcoder.jp/contests/abc371/tasks/abc371_d

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

ll N;
vll X, P;

vector<pll> Xsort;
vector<pll> sum;

ll Q;

void loop() {
    ll L, R;
    cin >> L >> R;

    ll right = upper_bound(sum.begin(), sum.end(), pll{R, (ll)1e15}) - sum.begin() - 1;
    ll left = lower_bound(sum.begin(), sum.end(), pll{L, (ll)-2e15}) - sum.begin() - 1;

    cout << sum[right].second - sum[left].second << "\n";
}

void solve() {
    Xsort.resize(N);
    for (ll i = 0;i < N;i++) Xsort[i] = {X[i], P[i]};
    sort(Xsort.begin(), Xsort.end());

    sum.assign(N + 1, {-2000000000, 0});
    for (ll i = 1;i <= N;i++) sum[i] = {Xsort[i - 1].first, Xsort[i - 1].second + sum[i - 1].second};

    cin >> Q;
    while (Q > 0) {
        Q--;

        loop();
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    X.resize(N);
    P.resize(N);
    for (ll i = 0;i < N;i++) cin >> X[i];
    for (ll i = 0;i < N;i++) cin >> P[i];
    
    solve();
    return 0;
}