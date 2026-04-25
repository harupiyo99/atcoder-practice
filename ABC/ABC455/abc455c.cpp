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

int N, K;
vll A;

void solve() {
    sort(A.begin(), A.end());

    vll sum(1, A[0]);
    ll cur = A[0];
    for (int i = 1;i < N;i++) {
        if (cur == A[i]) sum.back() += A[i];
        else {
            cur = A[i];
            sum.push_back(A[i]);
        }
    }

    sort(sum.begin(), sum.end());
    int len = sum.size();

    if (len <= K) cout << 0 << "\n";
    else {
        ll ans = 0;
        for (int i = 0;i < (len - K);i++) ans += sum[i];
        cout << ans << "\n";
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> K;
    A.resize(N);
    for (int i = 0;i < N;i++) cin >> A[i];

    solve();
    return 0;
}