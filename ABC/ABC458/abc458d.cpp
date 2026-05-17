// https://atcoder.jp/contests/abc458/tasks/abc458_d

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

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

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

ll X, Q;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    multiset<ll> high, low;
    vll m(Q + 1);
    m[0] = X;

    for (ll i = 1;i <= Q;i++) {
        ll A, B;
        cin >> A >> B;
        ll right = max(A, B), left = min(A, B);

        if (right == m[i - 1] && left == m[i - 1]) {
            m[i] = m[i - 1]; 
            high.insert(right);
            low.insert(left);
        }
        else if (right <= m[i - 1]) {
            low.insert(left);
            low.insert(right);

            ll can = *(--low.end());
            m[i] = can;
            low.erase(--low.end());
            high.insert(m[i - 1]);
        }
        else if (left >= m[i - 1]) {
            high.insert(left);
            high.insert(right);

            ll can = *high.begin();
            m[i] = can;
            high.erase(high.begin());
            low.insert(m[i - 1]);
        }
        else {
            high.insert(right);
            low.insert(left);
            m[i] = m[i - 1];
        }

        cout << m[i] << "\n";
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> X >> Q;

    solve();
    return 0;
}