// https://atcoder.jp/contests/abc365/tasks/abc365_d

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
string S;

void solve() {
    vi dpR(N + 1, -1), dpP(N + 1, -1), dpS(N + 1, -1);
    dpR[0] = 0;
    dpP[0] = 0;
    dpS[0] = 0;

    for (int i = 1;i <= N;i++) {
        if (S[i] == 'R') {
            dpP[i] = max(dpS[i - 1] + 1, dpR[i - 1] + 1);
            dpR[i] = max(dpP[i - 1], dpS[i - 1]);
        }
        else if (S[i] == 'S') {
            dpR[i] = max(dpP[i - 1] + 1, dpS[i - 1] + 1);
            dpS[i] = max(dpP[i - 1], dpR[i - 1]);
        }
        else {
            dpS[i] = max(dpP[i - 1] + 1, dpR[i - 1] + 1);
            dpP[i] = max(dpR[i - 1], dpS[i - 1]);
        }
    }

    cout << max({dpR[N], dpS[N], dpP[N]}) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    cin >> S;
    S = " " + S;
    
    solve();
    return 0;
}