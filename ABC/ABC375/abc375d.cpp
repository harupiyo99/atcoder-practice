// https://atcoder.jp/contests/abc375/tasks/abc375_d

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

string S;
ll N;

void solve() {
    vvll dist(26);

    for (ll i = 0;i < 26;i++) {
        char C = 'A' + i;

        ll d = 0;
        bool judge = false;
        for (ll j = 0;j < N;j++) {
            if (judge) d++;

            if (!judge && S[j] == C) judge = true;
            else if (S[j] == C) {
                dist[i].push_back(d - 1);
                d = 0;
            }
        }
    }

    ll ans = 0;

    for (ll i = 0;i < 26;i++) {
        ll len = dist[i].size();

        vll sum(len);
        if (len == 0) continue;
        else {
            sum[0] = dist[i][0];
            ans += sum[0];
        }
        for (ll j = 1;j < len;j++) {
            sum[j] = dist[i][j] * (j + 1) + j + sum[j - 1];
            ans += sum[j];
        }
    }

    cout << ans << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    
    solve();
    return 0;
}