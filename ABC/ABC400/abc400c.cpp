// https://atcoder.jp/contests/abc400/tasks/abc400_c

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

void solve() {
    ll inf = 1e9;
    ll l = 0, r = inf, mid, ansb;
    while (l <= r) {
        mid = (l + r) / 2;

        if (mid * mid > N / 2) r = mid - 1;
        else if (mid * mid < N / 2) {
            l = mid + 1;
            ansb = mid;
        }
        else {
            ansb = mid;
            break;
        }
    }

    l = 0; r = inf;
    ll ansc;
    while (l <= r) {
        mid = (l + r) / 2;

        if (mid * mid > N / 4) r = mid - 1;
        else if (mid * mid < N / 4) {
            l = mid + 1;
            ansc = mid;
        }
        else {
            ansc = mid;
            break;
        }
    }

    cout << ansb + ansc << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    
    solve();
    return 0;
}