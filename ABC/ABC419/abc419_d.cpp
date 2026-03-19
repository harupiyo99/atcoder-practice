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
    
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    vi log(N+1, 0);
    for (int i = 0;i < M;i++) {
        int L, R;
        cin >> L >> R;
        L--;
        R--;
        log[L]++;
        log[R+1]--;
    }

    vi rev(N, 0);
    rev[0] = log[0];
    if (rev[0] % 2 == 0) cout << S[0];
    else cout << T[0];

    for (int i = 1;i < N;i++) {
        rev[i] = rev[i-1] + log[i];

        if (rev[i] % 2 == 0) cout << S[i];
        else cout << T[i];
    }
    cout << "\n";
    return 0;
}