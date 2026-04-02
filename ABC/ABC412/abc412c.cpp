// https://atcoder.jp/contests/abc412/tasks/abc412_c

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

ll solve() {
    ll N;
    cin >> N;
    vll S(N);
    for (ll i = 0;i < N;i++) cin >> S[i];

    sort(S.begin() + 1, S.end() - 1);

    ll ans = 2;

    if (2 * S[0] >= S[N-1]) return ans;
    else {
        ll cur = 0;
        while (ans < N) {
            auto itr = upper_bound(S.begin() + 1, S.end() - 1, 2 * S[cur]);
            ll memo = distance(S.begin(), itr) - 1;

            ans++;
            if (2 * S[memo] >= S[N-1]) return ans;
            else cur = memo;
        }
        if (ans == N && S[N-1] )
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    
    while (T > 0) {
        T--;

        cout << solve() << "\n";
    }
    return 0;
}