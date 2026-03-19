// https://atcoder.jp/contests/abc416/tasks/abc416_c

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

vs ans;

void dfs(string crr, int count, int K, const vs& S) {
    if (count == K) {
        ans.push_back(crr);
        return;
    }
    for (string s : S) {
        dfs(crr + s, count + 1, K, S);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, K, X;
    cin >> N >> K >> X;
    vs S(N);
    for (int i = 0;i < N;i++) cin >> S[i];

    dfs("", 0, K, S);
    sort(ans.begin(), ans.end());

    cout << ans[X-1] << "\n";
    return 0;
}