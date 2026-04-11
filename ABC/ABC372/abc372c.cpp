// https://atcoder.jp/contests/abc372/tasks/abc372_c

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

ll N, Q;
string S;
ll abc;

void solve() {
    ll X;
    char C;
    cin >> X >> C;
    X--;

    ll l, r;
    if (X > N-3 && X < 2) {
        r = N-1;
        l = 0;
    }
    else if (X > N - 3) {
        r = N-1;
        l = X - 2;
    } 
    else if (X < 2) {
        r = X + 2;
        l = 0;
    }
    else {
        r = X + 2;
        l = X - 2;
    }

    ll count = 0;
    for (ll i = l;i <= r - 2;i++) if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') count++;

    S[X] = C;

    ll count2 = 0;
    for (ll i = l;i <= r - 2;i++) if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') count2++;

    abc += (count2 - count);
    cout << abc << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> Q;
    cin >> S;

    abc = 0;
    for (ll i = 0;i < N-2;i++) if (S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') abc++;

    while (Q > 0) {
        Q--;

        solve();
    }
    return 0;
}