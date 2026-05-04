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
    if (N == 1) {
        cout << 1 << "\n";
        return;
    }

    vll next(1, 0);
    for (int i = 1;i < N;i++) if (S[i] == S[i - 1]) next.push_back(i);
    next.push_back(N);

    ll len = next.size();
    ll ans = 0;
    for (int i = 1;i < len;i++) ans += (((next[i] - next[i - 1]) * (next[i] - next[i - 1] + 1) / 2) + w) % w;
    
    cout << (ans + w) % w << "\n";
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