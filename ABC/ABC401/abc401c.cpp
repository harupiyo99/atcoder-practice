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
    
    ll N, K;
    cin >> N >> K;

    vll A(N+1, 0), sum(N+2, 0);
    for (int i = 0;i <= min(N, K-1);i++) {
        A[i] = 1;
        sum[i + 1] = sum[i] + A[i];
    }
    for (int i = K;i <= N;i++) {
        A[i] = sum[(i-1) + 1] - sum[(i-K-1) + 1];
        sum[i + 1] = (sum[i] + A[i] + 1000000000) % 1000000000;
    }

    cout << (A[N] + 1000000000) % 1000000000 << "\n";
    return 0;
}