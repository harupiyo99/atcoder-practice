// https://atcoder.jp/contests/abc431/tasks/abc431_d

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>; 
using vvll = vector<vector<ll>>;
using vs = vector<string>;

using pii = pair<int, int>;
using pis = pair<int, string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    cin >> N;

    vll W(N), H(N), B(N);
    for (ll i = 0;i < N;i++) cin >> W[i] >> H[i] >> B[i];

    ll sumB = 0, sumW = 0;
    for (ll i = 0;i < N;i++) sumB += B[i];
    for (ll i = 0;i < N;i++) sumW += W[i];

    vvll dp(N+1, vll(sumW+1, -1));
    dp[0][0] = 0;
    for (ll i = 1;i <= N;i++) for (ll j = 0;j <= sumW;j++) {
        if (j < 2*W[i-1]) dp[i][j] = max(dp[i][j], dp[i-1][j]);
        else {
            if (dp[i-1][j-2*W[i-1]] != -1) {
                dp[i][j] = max({dp[i-1][j - 2*W[i-1]] + (H[i-1] - B[i-1]), dp[i-1][j], dp[i][j]});
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
            }
        }
    }

    ll ans = 0;
    for (ll i = 0;i <= sumW;i++) ans = max(ans, dp[N][i] + sumB);

    cout << ans << "\n";
    return 0;
}