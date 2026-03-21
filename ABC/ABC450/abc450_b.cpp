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
    
    int N;
    cin >> N;
    vvi C(N, vi(N+1, 0));
    for (ll i = 1;i < N;i++) {
        for (int j = i + 1;j <= N;j++) {
            cin >> C[i][j];
        }
    }

    bool ans = false;
    for (int a = 1;a <= N-2;a++) {
        for (int b = a+1;b <= N-1;b++) {
            for (int c = b+1;c <= N;c++) {
                if (C[a][c] > C[a][b] + C[b][c]) ans = true;
            }
            if (ans) break;
        }
        if (ans) break;
    }

    if (ans) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}