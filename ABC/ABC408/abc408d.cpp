// https://atcoder.jp/contests/abc408/tasks/abc408_d

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

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> S;

    vi A(N + 1, 0), B(N + 1, 0), C(N + 1, 0), Cmax(N + 1, 0);
    Cmax[0] = 0;
    rep(i, N) {
        if (S[i] == '0') {
            A[i + 1] = A[i] + 1;
            B[i + 1] = B[i];
        }
        else {
            B[i + 1] = B[i] + 1;
            A[i + 1] = A[i];
        }

        C[i + 1] = A[i + 1] - B[i + 1];
        Cmax[i + 1] = max(Cmax[i], C[i + 1]);
    }

    int ans = 10000000;
    for (int i = 0;i <= N;i++) {
        ans = min(ans, C[i] - Cmax[i]);
    }

    cout << ans + B[N] << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;

    while (T > 0) {
        T--;

        solve();
    }
    return 0;
}