// https://atcoder.jp/contests/abc391/tasks/abc391_c

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

void solve() {
    int N, Q;
    cin >> N >> Q;

    vll peg(N), pnum(N, 1);
    for (ll i = 0;i < N;i++) {
        peg[i] = i;
    }

    int ans = 0;
    while (Q > 0) {
        Q--;

        int num;
        cin >> num;

        if (num == 1) {
            int P, H;
            cin >> P >> H;
            P--;
            H--;

            if (pnum[peg[P]] == 2) ans--;
            pnum[peg[P]]--;

            peg[P] = H;
            if (pnum[H] == 1) ans++;
            pnum[H]++;
        }
        else {
            cout << ans << "\n";
        }
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}