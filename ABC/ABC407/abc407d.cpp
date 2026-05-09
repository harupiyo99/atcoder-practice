// https://atcoder.jp/contests/abc407/tasks/abc407_d

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
#include <iterator>

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

int H, W;
vvll A;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> H >> W;
    A.resize(H, vll(W));
    rep(i, H) rep(j, W) cin >> A[i][j];

    vll curboard(1, 0);
    const ll vertical = (1 << W) + 1, horizontal = 3;

    for (ll i = 0, bit = 0;i < H;i++) {
        for (int j = 0;j < W;j++,bit++) {
            vll memo;

            for (const ll b : curboard) {
                if (j + 1 < W && !(b & horizontal << bit)) memo.push_back(b | (horizontal << bit)); 
                if (i + 1 < H && !(b & vertical << bit)) memo.push_back(b | vertical << bit);
            }

            ranges::move(memo, back_inserter(curboard));
        }
    }

    ll ans = 0;
    for (ll b : curboard) {
        ll now = 0;
        for (int i = 0, bit = 0;i < H;i++) {
            for (int j = 0;j < W;j++, bit++) {
                if (1 & ~b >> bit) now ^= A[i][j];
            }
        }

        ans = max(ans, now);
    }

    cout << ans << "\n";
    return 0;
}