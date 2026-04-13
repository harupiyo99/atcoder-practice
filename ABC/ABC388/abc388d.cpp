// https://atcoder.jp/contests/abc388/tasks/abc388_d

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

ll N;
vll A;

void solve() {
    vll dif(N + 1, 0), stone(N + 1, 0), B(N, 0);
    
    if (A[0] != 0) {
        dif[1]++;
        if (N - 1 < A[0]) B[0] = A[0] - (N - 1);
        else dif[A[0] + 1]--;
    }
    for (ll i = 1;i < N;i++) {
        stone[i] = stone[i - 1] + dif[i];

        if (stone[i] + A[i] != 0) {
            dif[i + 1]++;
            if (N - 1 - i < A[i] + stone[i]) B[i] = A[i] + stone[i] + i - (N - 1);
            else dif[i + A[i] + stone[i] + 1]--;
        }
    }

    for (ll i = 0;i < N;i++) cout << B[i] << " ";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    for (ll i = 0;i < N;i++) cin >> A[i];
    
    solve();
    return 0;
}