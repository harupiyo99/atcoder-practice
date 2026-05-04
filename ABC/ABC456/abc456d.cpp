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

const ll w = 998244353;

string S;
int N;

void solve() {
    ll a = 0, b = 0, c = 0;
    for (ll i = N - 1;i >= 0;i--) {
        if (S[i] == 'a') {
            a += (b + c + 1);
        }
        else if (S[i] == 'b') {
            b += (a + c + 1);
        }
        else {
            c += (a + b + 1);
        }

        a = (a + w) % w;
        b = (b + w) % w;
        c = (c + w) % w;
    }

    ll ans = (a + b + c + w) % w;
    cout << ans << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    
    solve();
    return 0;
}