// https://atcoder.jp/contests/abc369/tasks/abc369_d

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
vll A;

void solve() {
    vll dpE(N + 1), dpO(N + 1);
    dpE[0] = 0;
    dpO[0] = -2e18;

    for (ll i = 1;i <= N;i++) {
        dpE[i] = max(dpE[i - 1], dpO[i - 1] + 2 * A[i]);
        dpO[i] = max(dpO[i - 1], dpE[i - 1] + A[i]);
    }

    cout << max(dpE[N], dpO[N]) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N + 1);
    for (ll i = 1;i <= N;i++) cin >> A[i];
    
    solve();
    return 0;
}