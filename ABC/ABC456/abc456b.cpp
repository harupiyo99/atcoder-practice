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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi me = {4, 5, 6};
    
    vvi A(3, vi(6));
    for (ll i = 0;i < 3;i++) for (int j = 0;j < 6;j++) cin >> A[i][j];

    int ans = 0;
    do {
        vi log(3, 0);
        for (int i = 0;i < 3;i++) {
            for (int j = 0;j < 6;j++) if (A[i][j] == me[i]) log[i]++;
        }
        ans += (log[0] * log[1] * log[2]);
    } while (next_permutation(me.begin(), me.end()));

    cout << fixed << setprecision(10) << ((double)(ans) / (double)(216)) << "\n";
    return 0;
}