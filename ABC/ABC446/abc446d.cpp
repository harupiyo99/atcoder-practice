// https://atcoder.jp/contests/abc446/tasks/abc446_d

// https://atcoder.jp/contests/tessoku-book/submissions/me

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>       
#include<queue>
#include<cmath>
#include<iomanip>

using namespace std;
using ll = long long int;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vector<int>>; 
using vvll = vector<vector<ll>>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vll A(N);
    for (ll i = 0;i < N;i++) cin >> A[i];

    ll len = 0;
    vll dp(N),L(N);
    for (ll i = 0;i < N;i++) {
        auto it = lower_bound(L.begin(),L.begin() + len,A[i]);
        ll pos = distance(L.begin(), it);
        dp[i] = pos + 1;

        L[dp[i] - 1] = A[i];
        if (dp[i] > len) len++;
    }

    cout << len << "\n";
    return 0;
}
