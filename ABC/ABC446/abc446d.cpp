#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;

    map<ll, ll> dp;
    ll len = 0;

    for (ll i = 0; i < N; i++) {
        ll A;
        cin >> A;

        dp[A] = dp[A - 1] + 1;
        
        len = max(len, dp[A]);
    }

    cout << len << "\n";

    return 0;
}
