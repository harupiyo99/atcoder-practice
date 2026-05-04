// https://atcoder.jp/contests/abc426/tasks/abc426_d

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

    char cur = S[0];
    int l = 0, r = 0, lmax1 = 0, rmax1 = 0, lmax0 = 0, rmax0 = 0;
    int cnt0 = 0, cnt1 = 0;
    if (S[0] == '0') cnt0++;
    else cnt1++;

    for (int i = 1;i < N;i++) {
        if (S[i] == '0') cnt0++;
        else cnt1++;

        if (cur == S[i]) r++;
        else {
            if (cur == '0') {
                if (rmax0 - lmax0 <= r - l) {
                    rmax0 = r;
                    lmax0 = l;
                }
            }
            else {
                if (rmax1 - lmax1 <= r - l) {
                    rmax1 = r;
                    lmax1 = l;
                }
            }
            cur = S[i];
            l = i;
            r = l;
        }
    }

    if (cur == '0') {
            if (rmax0 - lmax0 <= r - l) {
                rmax0 = r;
                lmax0 = l;
            }
        }
    else {
        if (rmax1 - lmax1 <= r - l) {
            rmax1 = r;
            lmax1 = l;
        }
    }

    if (r - l + 1 == N) {
        cout << 0 << "\n";
        return;
    }

    int ans;
    ans = min(2 * (cnt0 - (rmax0 - lmax0 + 1)) + cnt1, 2 * (cnt1 - (rmax1 - lmax1 + 1)) + cnt0);

    cout << ans << "\n";
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