// https://atcoder.jp/contests/abc416/tasks/abc416_d

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

int T;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll M;
    cin >> N >> M;
    vll A(N), B(N);
    rep(i, N) cin >> A[i];
    rep(i, N) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vb Aused(N, false);
    int cur = N - 1;
    int r = lower_bound(B.begin(), B.end(), M - A[N - 1]) - B.begin();
    for (int i = r;i < N;i++) {
        int l = lower_bound(A.begin(), A.end(), M - B[i]) - A.begin();
        if (cur >= l) {
            Aused[cur] = true;
            B[i] = (A[cur] + B[i] + M) % M;
            cur--;
        }
    }

    ll ans = 0;
    rep(i, N) {
        if (!Aused[i]) ans += A[i];
        
        ans += B[i];
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    while (T > 0) {
        T--;

        solve();
    }
    return 0;
}