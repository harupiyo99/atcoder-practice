// https://atcoder.jp/contests/abc447/tasks/abc447_d

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
    
    string S;
    cin >> S;

    int len = S.size();
    vvi dp(len, vi(3, 0));

    if (S[0] == 'A') dp[0][0] = 1;
    for (int i = 1;i < len;i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 1][2];

        if (S[i] == 'A') dp[i][0]++;

        if (S[i] == 'B') {
            if (dp[i - 1][0] - dp[i - 1][1] >= 1) dp[i][1]++;
        }

        if (S[i] == 'C') {
            if (dp[i - 1][1] != 0) {
                dp[i][2]++;
                dp[i][0]--;
                dp[i][1]--;
            }
        }
    }

    cout << dp[len - 1][2] << "\n";
    return 0;
}