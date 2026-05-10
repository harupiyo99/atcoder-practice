// https://atcoder.jp/contests/abc403/tasks/abc403_d

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
#include <unordered_set>
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

int N, D;
vi A;

void solve() {
    if (D == 0) {
        set<int> memo;
        rep(i, N) memo.insert(A[i]);

        cout << N - memo.size() << "\n";
        return;
    }
    else {
        vi C(1000009, 0);
        rep(i, N) C[A[i]]++;

        int ans = 0;
        rep(i, D) {
            int r = (1000000 - i) / D;

            if (r == 0) continue;

            vi dp(r + 1);
            dp[0] = 0;
            dp[1] = min(C[i], C[i + D]);

            for (int j = 2;j <= r;j++) {
                dp[j] = min(C[i + D * (j)] + dp[j - 1], C[i + D * (j - 1)] + dp[j - 2]);
            }

            ans += dp[r];
        }

        cout << ans << "\n";
        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> D;
    A.resize(N);
    rep(i, N) cin >> A[i];

    solve();
    return 0;
}