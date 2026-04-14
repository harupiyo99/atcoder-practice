// https://atcoder.jp/contests/abc379/tasks/abc379_d

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

ll Q;

void solve() {
    ll cur = 0;
    priority_queue<ll> plants;

    while (Q > 0) {
        Q--;

        int n;
        cin >> n;
        
        if (n == 1) {
            plants.push(-1 * cur);
        }
        else if (n == 2) {
            ll T;
            cin >> T;

            cur += T;
        }
        else {
            ll H;
            cin >> H;
            ll victim = 0;

            while (!plants.empty() && plants.top() + cur >= H) {
                plants.pop();
                victim++;
            }

            cout << victim << "\n";
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> Q;

    solve();
    return 0;
}