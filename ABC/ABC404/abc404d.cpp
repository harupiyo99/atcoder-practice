// https://atcoder.jp/contests/abc404/tasks/abc404_d

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

ll N, M;
vll C, K;

vvll animals;
vll cases;
ll N3;
ll ans;

void solve() {
    cases.resize(N);
    cases[0] = 1;
    for (ll i = 1;i < N;i++) cases[i] = cases[i-1] * 3;

    N3 = cases[N-1] * 3;
    ans = 1000000000000;
    for (ll i = 2;i < N3;i++) {
        ll n = i;
        ll price = 0;

        vll times(M);
        for (ll j = N-1;j >= 0;j--) {
            price += C[j] * (n / cases[j]);

            for (ll k : animals[j]) times[k] += (n / cases[j]);
            n -= cases[j] * (n / cases[j]);
        }

        bool judge = true;
        for (ll j = 0;j < M;j++) if (times[j] < 2) judge = false;
        if (judge) ans = min(ans, price);
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    C.resize(N);
    for (ll i = 0;i < N;i++) cin >> C[i];

    K.resize(M);
    animals.resize(N);
    for (ll i = 0;i < M;i++) {
        cin >> K[i];
        
        for (ll j = 0;j < K[i];j++) {
            ll A;
            cin >> A;
            A--;

            animals[A].push_back(i);
        }
    }
    
    solve();
    return 0;
}