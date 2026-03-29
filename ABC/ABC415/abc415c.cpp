// https://atcoder.jp/contests/abc415/submissions/74535593

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
    int N;
    string S;
    cin >> N >> S;

    S = "0" + S;
    int len = S.size();
    
    vb visited(len, false);
    visited[0] = true;
    rep(i, len) {
        if (!visited[i]) continue;

        int memo = i;

        for (int j = N-1;j >= 0;j--) {
            if (memo / (1 << j) == 0) {
                if (S[i + (1 << j)] == '0') visited[i + (1 << j)] = true; 
            }
            else memo -= (1 << j);
        }
    }

    if (visited[len-1]) cout << "Yes\n";
    else cout << "No\n";
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