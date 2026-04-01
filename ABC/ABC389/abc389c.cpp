// https://atcoder.jp/contests/abc389/tasks/abc389_c

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
    int Q;
    cin >> Q;

    ll cur = 0, len_sum = 0, del = 0;
    vll snake;
    
    while (Q > 0) {
        Q--;

        ll n;
        cin >> n;

        if (n == 1) {
            ll l;
            cin >> l;
            snake.push_back(cur);
            cur += l;
        }

        else if (n == 2) {
            len_sum = snake[del + 1];
            del++;
        }

        else {
            ll k;
            cin >> k;
            cout << snake[k - 1 + del] - len_sum << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}