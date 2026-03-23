#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <stack>
#include <queue>
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
    
    int N, M;
    cin >> N >> M;
    vi u(M), v(M);
    rep(i, M) {
        cin >> u[i] >> v[i];
        u[i]--;
        v[i]--;
    }

    ll ans = 100000000;
    rep(i, 1 << N) {
        int wara = i;
        vector<bool> white(N);
        for (int j = N-1;j >= 0;j--) {
            if (wara / (1 << j) == 1) {
                wara -= (1 << j);
                white[j] = false;
            }
            else white[j] = true;
        }

        ll anscur = 0;
        for (int i = 0;i < M;i++) {
            if (white[u[i]] == white[v[i]]) anscur++;
        }

        ans = min(ans, anscur);
    }
    
    cout << ans << "\n";
    return 0;
}