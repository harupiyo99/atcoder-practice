// https://atcoder.jp/contests/abc358/tasks/abc358_d

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
vll A, B;

void solve() {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vll R(M);
    for (ll i = M - 1;i >= 0;i--) {
        R[i] = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        if (N - R[i] - (M - i) < 0) {
            cout << -1 << "\n";
            return;
        }
    }

    vll chose(N, false);
    ll ans = 0;
    ll j;
    bool flag = false;
    for (ll i = 0;i < M;i++) {
        if (!chose[R[i]]) {
            ans += A[R[i]];
            chose[R[i]] = true;
            if (flag) flag = false;
        }
        else {
            if (!flag) {
                j = R[i] + 1;
                flag = true;
            }
            while (chose[j]) j++;
            ans += A[j];
            chose[j] = true;
        }
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
    B.resize(M);
    for (ll i = 0;i < N;i++) cin >> A[i];
    for (ll i = 0;i < M;i++) cin >> B[i];
    
    solve();
    return 0;
}