// https://atcoder.jp/contests/abc441/tasks/abc441_c

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>

using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>; 
using vvll = vector<vector<ll>>;
using vs = vector<string>;

using pii = pair<int, int>;
using pis = pair<int, string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N,K,X;
    cin >> N >> K >> X;
    vll A(N);
    for (ll i = 0;i < N;i++) cin >> A[i];

    sort(A.begin(), A.end());

    ll sumsake = 0, ans = -1;
    for (ll i = K - 1;i >= 0;i--) {
        sumsake += A[i];
        if (sumsake >= X) {
            ans = N - i;
            break;
        }
    }

    cout << ans << "\n";
    return 0;
}