// https://atcoder.jp/contests/abc242/tasks/abc242_c

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
    
    ll N;
    cin >> N;

    vvll X(N,vll(10));

    for (int i = 1;i < 10;i++) X[0][i] = 1;

    for (ll i = 1;i < N;i++) {
        for (int j = 1;j < 10;j++) {
            if (j == 1) {
                X[i][j] = X[i - 1][1] + X[i - 1][2];
            }
            else if (j == 9) {
                X[i][j] = X[i - 1][8] + X[i - 1][9];
            }
            else {
                X[i][j] = X[i - 1][j - 1] + X[i - 1][j] + X[i - 1][j + 1];
            }

            X[i][j] %= 998244353;
        }
    }

    ll ans = 0;
    for (int i = 1;i < 10;i++) {
        ans = (ans + X[N - 1][i]) % 998244353;
    }

    cout << ans << "\n";
    return 0;
}