#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <stack>
#include <queue>
#include<set>
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vi A(N), B(N);
    for (int i = 0;i < N;i++) cin >> A[i] >> B[i];

    int M;
    cin >> M;
    vs S(M);
    msi memo;
    for (int i = 0;i < M;i++) {
        cin >> S[i];
        memo[S[i]] = i;
    }

    vector<vs> str(10);
    rep(i, M) str[S[i].size() - 1].push_back(S[i]);
    
    vector<set<char>> roko(10);
    rep(i, N) for (string s : str[A[i]-1]) {
        roko[i].insert(s[B[i] - 1]);
    }

    vs ans(M, "No\n");
    for (string s : str[N-1]) {
        bool judge = true;
        rep(i, N) {
            if (roko[i].count(s[i]) == 0) {
                judge = false;
                break;
            }
        }
        if (judge) {
            ans[memo[s]] = "Yes\n";
        }
    }

    rep(i, M) cout << ans[i];

    return 0;
}