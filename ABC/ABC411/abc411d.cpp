// https://atcoder.jp/contests/abc411/tasks/abc411_d

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

int N, Q;
vi n, p;
vs s;

int cur;
string ans;

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int t = Q - 1;t >= 0;t--) {
        if (n[t] == 1 && cur == p[t]) cur = 0;
        else if (n[t] == 2 && cur == p[t]) ans += s[t];
        else if (n[t] == 3 && cur == 0) cur = p[t];
    }

    int len = ans.size();
    for (int i = len - 1;i >= 0;i--) cout << ans[i];
    cout << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;

    cur = 0;
    ans = " ";
    n.resize(Q);
    p.resize(Q);
    s.resize(Q);
    for (int i = 0;i < Q;i++) {
        int nc, pc;
        cin >> nc >> pc;

        if (nc == 1) {
            n[i] = nc;
            p[i] = pc;
        }
        else if (nc == 2) {
            string sc;
            cin >> sc;

            reverse(sc.begin(), sc.end());
            n[i] = nc;
            p[i] = pc;
            s[i] = sc;
        }
        else {
            n[i] = nc;
            p[i] = pc;
        }
    }

    solve();
    return 0;
}