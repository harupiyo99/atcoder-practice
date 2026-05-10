// https://atcoder.jp/contests/abc406/tasks/abc406_c

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
vll P;

void solve() {
    vll memo;
    ll max, min;

    if (P[0] < P[1]) min = 0;

    for (ll i = 1;i < N - 1;i++) {
        if (P[i - 1] < P[i] && P[i] > P[i + 1]) {
            max = i;
            memo.push_back(max - min);
        }
        else if (P[i - 1] > P[i] && P[i] < P[i + 1]) {
            min = i;
        }
    }

    if (P[N - 1] > P[N - 2]) {
        max = N - 1;
        memo.push_back(max - min);
    }

    ll len = memo.size();
    if (memo.empty() || memo.size() == 1) {
        cout << 0 << "\n";
        return;
    }

    ll ans = 0;
    for (ll i = 1;i < len;i++) {
        ans += memo[i] * memo[i - 1];
    }

    cout << ans << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    P.resize(N);
    for (ll i = 0;i < N;i++) cin >> P[i];
    
    solve();
    return 0;
}