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
    
    int N,M;
    cin >> N >> M;
    vi A(N), B(N), C(M);
    for (int i = 0;i < M;i++) cin >> C[i];
    for (int i = 0;i < N;i++) {
        cin >> A[i] >> B[i];
        A[i]--;
    }

    vi use(M,0);
    int ans = 0;
    for (int i = 0;i < N;i++) {
        use[A[i]] += B[i];
    }
    for (int i = 0;i < M;i++) {
        ans += min(use[i], C[i]);
    }

    cout << ans << "\n";
    return 0;
}