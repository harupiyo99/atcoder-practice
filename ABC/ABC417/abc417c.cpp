#include <iostream>   
#include <vector>   
#include <algorithm>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
    vll A(N+1);
    vll graph1(400008, 0), graph2(200008, 0);
    for (ll i = 1;i <= N;i++) {
        cin >> A[i];
        graph1[A[i] + i]++;
        if (i - A[i] > 0) graph2[i - A[i]]++;  
    }

    ll ans = 0;
    for (ll i = 1;i <= 200008;i++) ans += (graph1[i] * graph2[i]);

    cout << ans << "\n";
    return 0;
}