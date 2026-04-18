// https://atcoder.jp/contests/abc366/tasks/abc366_d

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

int N;
vector<vvi> A;
int Q;

void solve() {
    vector<vvi> sum(N + 1, vvi(N + 1, vi(N + 1, 0)));

    for (int i = 1;i <= N;i++) for (int j = 1;j <= N;j++) for (int k = 1;k <= N;k++) sum[i][j][k] = sum[i][j][k - 1] + A[i][j][k];
    for (int i = 1;i <= N;i++) for (int k = 1;k <= N;k++) for (int j = 1;j <= N;j++) sum[i][j][k] += sum[i][j - 1][k];
    for (int j = 1;j <= N;j++) for (int k = 1;k <= N;k++) for (int i = 1;i <= N;i++) sum[i][j][k] += sum[i - 1][j][k];

    cin >> Q;
    while (Q > 0) {
        Q--;

        int lx, rx, ly, ry, lz, rz;
        cin >> lx >> rx >> ly >> ry >> lz >> rz;

        cout << sum[rx][ry][rz] - (sum[rx][ry][lz - 1] + sum[rx][ly - 1][rz] + sum[lx - 1][ry][rz] - (sum[lx - 1][ly - 1][rz] + sum[lx - 1][ry][lz - 1] + sum[rx][ly - 1][lz - 1]) + sum[lx - 1][ly - 1][lz - 1]) << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N + 1, vvi(N + 1, vi(N + 1, 0)));
    for (int i = 1;i <= N;i++) for (int j = 1;j <= N;j++) for (int k = 1;k <= N;k++) cin >> A[i][j][k];
    
    solve();
    return 0;
}