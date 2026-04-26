// https://atcoder.jp/contests/abc362/tasks/abc362_c

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
vll L, R;
vector<pair<ll, pll>> A;

ll S;

void solve() {
    if (S < 0) {
        cout << "No" << "\n";
        return;
    }
    else {
        sort(A.begin(), A.end());

        ll border = 0;
        for (ll i = N - 1;i >= 0;i--) {
            S -= A[i].first;

            if (S <= 0) {
                border = i;
                break;
            }
        }
        if (S > 0) {
            cout << "No" << "\n";
            return;
        }
        else {
            cout << "Yes" << "\n";
            vll ans(N);
            for (ll i = 0;i < border;i++) ans[A[i].second.first] = A[i].second.second;
            ans[A[border].second.first] = S + A[border].first + A[border].second.second;
            for (ll i = border + 1;i < N;i++) ans[A[i].second.first] = A[i].first + A[i].second.second;

            for (ll i = 0;i < N;i++) cout << ans[i] << " ";
        }

        return;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    L.resize(N);
    R.resize(N);
    A.resize(N);
    for (ll i = 0;i < N;i++) {
        cin >> L[i] >> R[i];

        A[i] = {R[i] - L[i], {i, L[i]}};
        S -= L[i];
    }
    
    solve();
    return 0;
}