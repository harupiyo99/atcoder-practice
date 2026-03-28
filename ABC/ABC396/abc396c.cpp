// https://atcoder.jp/contests/abc396/tasks/abc396_c

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
    
    ll N, M;
    cin >> N >> M;
    vll B(N), W(M);
    for (ll i = 0;i < N;i++) cin >> B[i];
    for (ll i = 0;i < M;i++) cin >> W[i];

    sort(B.begin(), B.end());
    reverse(B.begin(), B.end());
    sort(W.begin(), W.end());
    reverse(W.begin(), W.end());

    vll Bsum(N), Wsum(M);
    ll Bzero = -1, Wzero = -1;

    Bsum[0] = B[0];
    for (ll i = 1;i < N;i++) {
        Bsum[i] = Bsum[i-1] + B[i];
        if (B[i] < 0 && B[i-1] >= 0) Bzero = i-1;
    }
    if (B[N-1] > 0) Bzero = N-1;
    Wsum[0] = W[0];
    for (ll i = 1;i < M;i++) {
        Wsum[i] = Wsum[i-1] + W[i];
        if (W[i] < 0 && W[i-1] >= 0) Wzero = i-1;
    }
    if (W[M-1] > 0) Wzero = M-1;

    if (Bzero == -1 && Wzero == -1) {
        cout << 0 << "\n";
        return 0;
    }
    else if (Bzero == -1) {
        ll ans = 0;
        for (ll i = 0;i <= Wzero;i++) {
            if (i <= N-1) ans = max(ans, Wsum[i] + Bsum[i]);
            else ans = max(ans, Bsum[N-1] + W[Wzero]);
        }
        cout << ans << "\n";
        return 0;
    }
    else if (Wzero == -1) {
        cout << Bsum[Bzero] << "\n";
        return 0;
    }

    ll ans = 0;
    if (Wzero <= Bzero) ans = Wsum[Wzero] + Bsum[Bzero];
    else {
        for (ll i = Bzero;i <= Wzero;i++) {
            if (i <= N-1) ans = max(ans, Bsum[i] + Wsum[i]);
        }
    }

    cout << ans << "\n";
    return 0;
}