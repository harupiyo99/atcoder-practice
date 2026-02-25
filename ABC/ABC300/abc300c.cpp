// https://atcoder.jp/contests/abc300/tasks/abc300_c

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
    
    int H,W;
    cin >> H >> W;
    vs C(H);
    for (int i = 0;i < H;i++) cin >> C[i];
    int N = min(H, W);
    vi S(N + 1,0);

    for (int i = 1;i < H - 1;i++) {
        for (int j = 1;j < W - 1;j++) {
            if (C[i][j] == '#' && C[i - 1][j - 1] == '#' && C[i - 1][j + 1] == '#' && C[i + 1][j - 1] == '#' && C[i + 1][j + 1] == '#') {
                int n = 1;
                while ((i - n >= 0) && (j - n >= 0) && (i + n < H) && (j + n < W) && (C[i - n][j - n] == '#')) {
                    n++;
                }
                S[n - 1]++;
            }
        }
    }

    for (int i = 1;i < N;i++) cout << S[i] << " ";
    cout << S[N] << "\n";
    return 0;
}