// https://atcoder.jp/contests/abc402/tasks/abc402_c

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
    
    ll N, M;
    cin >> N >> M;
    vll K(M);
    vvll A(M), graph(N);
    for (ll i = 0;i < M;i++) {
        cin >> K[i];
        for (ll j = 0;j < K[i];j++) {
            ll a;
            cin >> a;
            a--;
            A[i].push_back(a);
            graph[A[i][j]].push_back(i);
        }
    }
    vll B(N);
    ll ans = 0;
    for (ll i = 0;i < N;i++) {
        cin >> B[i];
        B[i]--;
        for (ll j : graph[B[i]]) {
            K[j]--;
            if (K[j] == 0) ans++; 
        }
        cout << ans << "\n";
    }
    return 0;
}