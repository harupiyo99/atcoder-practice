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
    
    int N, M;
    cin >> N >> M;
    vi A(N), B(N);
    vi konki(M, 0), raiki(M, 0);
    for (int i = 0;i < N;i++) {
        cin >> A[i] >> B[i];
        konki[A[i]-1]++;
        raiki[B[i]-1]++;
    }

    for (int i = 0;i < M;i++) {
        cout << raiki[i] - konki[i] << "\n";
    }
    return 0;
}