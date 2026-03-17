// https://atcoder.jp/contests/abc418/tasks/abc418_c

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
    
    ll N, Q;
    cin >> N >> Q;
    vll A(N);
    for (ll i = 0;i < N;i++) cin >> A[i];

    sort(A.begin(), A.end());
    vll sumA(N);
    sumA[0] = A[0];
    for (ll i = 1;i < N;i++) {
        sumA[i] = sumA[i-1] + A[i];
    }

    while (Q > 0) {
        Q--;
        ll B;
        cin >> B;

        ll ans = -1;
        if (B <= A[N-1]) {
            auto it = lower_bound(A.begin(), A.end(), B);
            int i = distance(A.begin(), it);
            if (i == 0) ans = ((B-1) *(N - i) + 1);
            else ans = (sumA[i-1] + (B-1) * (N-i) + 1);
        }

        cout << ans << "\n";
    }
    return 0;
}