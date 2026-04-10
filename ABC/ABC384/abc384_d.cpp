// https://atcoder.jp/contests/abc384/tasks/abc384_d

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N, S;
    cin >> N >> S;
    vll A(N + 1);
    for (ll i = 1;i <= N;i++) cin >> A[i];

    vll sumA(2 * N + 1, 0);
    for (ll i = 1;i <= N;i++) sumA[i] = sumA[i-1] + A[i];
    for (ll i = N + 1;i <= 2 * N;i++) sumA[i] = sumA[i - 1] + A[i - N];

    ll Snew;
    Snew = S % sumA[N];

    if (Snew == 0) {
        cout << "Yes" << "\n";
        return 0;
    }

    string ans = "No";

    ll r;
    for (ll l = 0;l < 2 * N;l++) {
        r = lower_bound(sumA.begin(), sumA.end(), Snew + sumA[l]) - sumA.begin();
        if (sumA[r] - sumA[l] == Snew) {
            ans = "Yes";
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}