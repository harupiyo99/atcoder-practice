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
    map<ll, ll> S, T;
    ll ans = 0;
    for (ll i = 0;i < N;i++) {
        cin >> A[i];
        if (A[i] % 3 == 0) S[A[i] / 3]++;
        if (A[i] % 7 == 0) T[A[i] / 7]++;
        if (A[i] % 5 == 0) ans += S[A[i] / 5] * T[A[i] / 5];
    }

    map<ll, ll> Sr, Tr;
    for (ll i = N-1;i >= 0;i--) {
        if (A[i] % 3 == 0) Sr[A[i] / 3]++;
        if (A[i] % 7 == 0) Tr[A[i] / 7]++;
        if (A[i] % 5 == 0) ans += Sr[A[i] /5] * Tr[A[i] / 5];
    }
    
    cout << ans << "\n";
    return 0;
}