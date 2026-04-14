// https://atcoder.jp/contests/abc385/tasks/abc385_c

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

int N;
vi H;

void solve() {
    int ans = 1;
    
    for (int k = 1;k < N;k++) {
        for (int j = 0;j < k;j++) {
            int cur = H[j], num = 1;
            for (int i = 1;i <= (N - 1) / k;i++) {
                if (H[j + i * k] != cur) {
                    num = 1;
                    cur = H[j + i * k];
                }
                else {
                    num++;
                }

                ans = max(ans, num);
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N;
    H.resize(N);
    for (int i = 0;i < N;i++) cin >> H[i];

    solve();
    return 0;
}