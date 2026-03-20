#include <iostream>   
#include <vector> 
#include <algorithm>

using namespace std;

using ll = long long;

using vll = vector<ll>; 
using vvll = vector<vector<ll>>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    cin >> N;
    vll A(N), B(N), C(N);
    for (ll i = 0;i < N;i++) cin >> A[i];
    for (ll i = 0;i < N;i++) cin >> B[i];
    for (ll i = 0;i < N;i++) cin >> C[i];

    ll sumB = 0;
    for (ll i = 0;i < N;i++) sumB += B[i];

    vll xsum(N-2);
    xsum[0] = A[0] - B[0];
    for (ll i = 1;i < N-2;i++) xsum[i] = xsum[i-1] + A[i] - B[i];
    vll ysum(N, 0), ysum_max(N, 0);
    ysum[N-1] = C[N-1] - B[N-1];
    ysum_max[N-1] = ysum[N-1];
    for (ll i = N-2;i > 1;i--) {
        ysum[i] = C[i] - B[i] + ysum[i+1];
        ysum_max[i] = max(ysum[i], ysum_max[i+1]);
    }

    ll ans = 0;
    for (ll i = 0;i < N-2;i++) {
        ans = max(ans, xsum[i] + ysum_max[i+2] + sumB);
    }

    cout << ans << "\n";
    return 0;
}