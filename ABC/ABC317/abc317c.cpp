// https://atcoder.jp/contests/abc317/tasks/abc317_c

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
using ll = long long int;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>; 
using pii = pair<int,int>;
using psi = pair<string,int>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;

    vi A(M),B(M);
    vll C(M);
    vvll d(N,vll(N,-1));
    for (int i = 0;i < M;i++) {
        cin >> A[i] >> B[i] >> C[i];
        A[i]--;
        B[i]--;
        d[A[i]][B[i]] = C[i];
        d[B[i]][A[i]] = C[i];
    }

    vvll dp(1 << N,vll(N, -1));
    for (int i = 0;i < N;i++) {
        dp[1 << i][i] = 0;
    }

    ll ans = 0;
    for (int S = 1;S < (1 << N);S++) {
        for (int v = 0;v < N;v++) {
            if (dp[S][v] == -1) continue;

            ans = max(ans, dp[S][v]);

            for (int u = 0;u < N;u++) {
                if (d[v][u] != -1 && !((S >> u) & 1)) {
                    int next = S + (1 << u);
                    dp[next][u] = max(dp[next][u], dp[S][v] + d[v][u]);
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}