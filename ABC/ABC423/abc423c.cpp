// https://atcoder.jp/contests/abc423/tasks/abc423_c

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
    
    int N, R;
    cin >> N >> R;

    vi L(N);
    for (int i = 0;i < N;i++) cin >> L[i];

    int start = 0, end = 0; 
    for (int i = 0;i < N;i++) {
        if (L[i] == 1) start++;
        else break; 
    }
    for (int i = N - 1;i >= 0;i--) {
        if (L[i] == 1) end++;
        else break;
    }

    int ans = 0;
    for (int i = R-1;i >= start;i--) {
        if (L[i] == 1) ans += 2;
        else ans++;
    }
    for (int i = R;i < N - end;i++) {
        if (L[i] == 1) ans += 2;
        else ans++;
    }

    cout << ans << "\n";
    return 0;
}