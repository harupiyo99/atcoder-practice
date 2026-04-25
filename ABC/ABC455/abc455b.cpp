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

int H, W;
vs S;

void solve() {
    ll ans = 0;

    for (int h1 = 0;h1 < H;h1++) for (int h2 = h1;h2 < H;h2++) for (int w1 = 0;w1 < W;w1++) for (int w2 = w1;w2 < W;w2++) {
        bool judge = true;

        for (int i = h1;i <= h2;i++) for (int j = w1;j <= w2;j++) {
            if (S[i][j] != S[h1 + h2 - i][w1 + w2 - j]) judge = false;
        }

        if (judge) ans++;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;
    S.resize(H);
    rep(i, H) cin >> S[i];
    
    solve();
    return 0;
}