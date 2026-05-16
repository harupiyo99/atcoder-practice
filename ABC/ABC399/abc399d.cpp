// https://atcoder.jp/contests/abc399/tasks/abc399_d

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

    ll N;
    cin >> N;
    vll A(2 * N);
    rep(i, 2 * N) {
        cin >> A[i];
        A[i]--;
    }

    vvll p(N);
    rep(i, 2 * N) p[A[i]].push_back(i);

    rep(i, N) if (p[i][1] - p[i][0] == 1) {
        p[i].pop_back();
        p[i].pop_back();
    }

    set<pll> ans;
    for (ll i = 0;i < 2 * N - 1;i++) {
        if (p[A[i]].size() == 0 || p[A[i + 1]].size() == 0) continue;

        vll v;
        v.push_back(p[A[i]][0]);
        v.push_back(p[A[i]][1]);
        v.push_back(p[A[i + 1]][0]);
        v.push_back(p[A[i + 1]][1]);

        sort(v.begin(), v.end());
        ll maxA = max(A[i], A[i + 1]), minA = min(A[i], A[i + 1]);
        if (v[1] - v[0] == 1 && v[3] - v[2] == 1) ans.insert({minA, maxA});
    }

    cout << ans.size() << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll T;
    cin >> T;
    
    while (T > 0) {
        T--;

        solve();
    }
    return 0;
}