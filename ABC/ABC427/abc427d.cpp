// https://atcoder.jp/contests/abc427/tasks/abc427_d

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <unordered_map>
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

void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    string S;
    cin >> S;
    vvi graph(N);
    for (int i = 0;i < M;i++) {
        int U, V;
        cin >> U >> V;
        U--; V--;

        graph[U].push_back(V);
    }

    vector<vb> dp(2 * K + 1, vb(N, false));
    for (int i = 0;i < N;i++) if (S[i] == 'A') dp[2 * K][i] = true;

    for (int i = 2 * K - 1;i >= 0;i--) {
        if (i % 2 == 1) {
            for (int j = 0;j < N;j++) {
                if (graph[j].empty()) continue;

                bool judge = false;
                for (int k : graph[j]) if(!dp[i + 1][k]) judge = true;
                if (judge) dp[i][j] = false;
                else dp[i][j] = true;
            }
        }
        else {
            for (int j = 0;j < N;j++) {
                if (graph[j].empty()) continue;

                bool judge = false;
                for (int k : graph[j]) if(dp[i + 1][k]) judge = true;
                if (judge) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    } 

    if (dp[0][0]) cout << "Alice" << "\n";
    else cout << "Bob" << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T > 0) {
        T--;

        solve();
    }
    return 0;
}