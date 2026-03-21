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
    
    ll N, K;
    cin >> N >> K;
    vll A(N);
    for (ll i = 0;i < N;i++) cin >> A[i];

    vll Adiv(N);
    for (ll i = 0;i < N;i++) Adiv[i] = A[i] % K;

    sort(Adiv.begin(), Adiv.end());

    queue<ll> As;
    for (ll i = 0;i < N;i++) {
        As.push(Adiv[i]);
    }

    ll ans = K + 810;
    for (ll i = 0;i < N;i++) {
        ll first = As.front();
        ll last = As.back();
        ans = min(last - first, ans);
        As.push(first+K);
        As.pop();
    }

    cout << ans << "\n";
    return 0;
}