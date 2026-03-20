#include <iostream>   
#include <vector>
#include <algorithm>
#include <map>

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
    vll A(N);
    for (ll i = 0;i < N;i++) cin >> A[i];

    map<ll, ll> memo3, memo7;
    ll ans = 0;
    for (ll i = 0;i < N;i++) {
        if (A[i] % 3 == 0) memo3[A[i] / 3]++;
        if (A[i] % 7 == 0) memo7[A[i] / 7]++;
        if (A[i] % 5 == 0) ans += memo3[A[i] / 5] * memo7[A[i] / 5];
    }
    map<ll, ll> nmemo3, nmemo7;
    for (ll i = N-1;i >= 0;i--) {
        if (A[i] % 3 == 0) nmemo3[A[i] / 3]++;
        if (A[i] % 7 == 0) nmemo7[A[i] / 7]++;
        if (A[i] % 5 == 0) ans += nmemo3[A[i] / 5] * nmemo7[A[i] / 5];
    }

    cout << ans << "\n";
    return 0;
}