// https://atcoder.jp/contests/abc408/tasks/abc408_c

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
    vi L(M), R(M);
    rep(i, M) cin >> L[i] >> R[i];

    vi edge(N+1, 0);
    rep(i, M) {
        edge[L[i]-1]++;
        edge[R[i]]--;
    }
    vi str(N, 0);
    str[0] = edge[0];
    for (int i = 1;i < N;i++) str[i] = str[i-1] + edge[i];

    int ans = 100000000;
    for (int i = 0;i < N;i++) ans = min(ans, str[i]);

    cout << ans << "\n";
    return 0;
}