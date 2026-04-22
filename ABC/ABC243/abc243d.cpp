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

ll N, X;
string S;

void solve() {
    ll cur = X;
    string memo;

    for (ll i = 0;i < N;i++) {
        if (!memo.empty() && S[i] == 'U' && (memo.back() == 'L' || memo.back() == 'R')) {
            memo.pop_back();
        }
        else {
            memo.push_back(S[i]);
        }
    }
    for (char c : memo) {
        if (c == 'U') cur /= 2;
        else if (c == 'R') cur = cur * 2 + 1;
        else {
            cur *= 2;
        }
    }

    cout << cur << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> X;
    cin >> S;

    solve();

    return 0;
}