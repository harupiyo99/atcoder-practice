// https://atcoder.jp/contests/abc422/tasks/abc422_d

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

ll N, K;

void solve() {
    if (K % (1 << N) == 0) {
        cout << 0 << "\n";
        for (ll i = 0;i < (1 << N);i++) cout << (K / (1 << N)) << " ";
        return;
    } 
    vll ans(1, K);
    for (ll i = 0;i < N;i++) {
        vll ins;
        for (ll j : ans) {
            ins.push_back(j / 2);
            ins.push_back(j - j / 2);
        }
        ans = ins;
    }
    cout << 1 << "\n";
    for (ll i = 0;i < (1 << N);i++) cout << ans[i] << " ";
    
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;
    
    solve();
    return 0;
}