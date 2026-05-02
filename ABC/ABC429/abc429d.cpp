// https://atcoder.jp/contests/abc429/tasks/abc429_d

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

ll N, M, C;
vll A;

void solve() {
    sort(A.begin(), A.end());

    vll checkc(1, 0), checksum(1, 0);
    ll cur = 0, num = 0;
    for (ll i = 0;i < 2 * N;i++) {
        if (cur != A[i]) {
            checkc.push_back(A[i]); 
            checksum.push_back(0);
            cur = A[i];
            num++;
        }
        checksum[num] = i + 1;
    }

    ll cnt = 1, ans = 0;
    while (checkc[cnt - 1] < M) {
        ll r = lower_bound(checksum.begin(), checksum.end(), checksum[cnt - 1] + C) - checksum.begin();

        ans += ((checksum[r] - checksum[cnt - 1]) * (min(checkc[cnt], M) - checkc[cnt - 1]));

        cnt++;
    }

    cout << ans << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> C;
    A.resize(2 * N);
    for (ll i = 0;i < N;i++) {
        cin >> A[i];
        A[i + N] = A[i] + M;
    }
    
    solve();
    return 0;
}