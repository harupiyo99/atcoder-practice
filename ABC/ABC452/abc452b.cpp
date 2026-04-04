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
    
    int H, W;
    cin >> H >> W;

    vs masu(H);
    for (int i = 0;i < H;i++) {
        if (i == 0 || i == H-1) for (int j = 0;j < W;j++) masu[i].push_back('#');
        else for (int j = 0;j < W;j++) {
            if (j == 0 || j == W-1) masu[i].push_back('#');
            else masu[i].push_back('.');
        }
    }

    for (int i = 0;i < H;i++) cout << masu[i] << "\n";
    return 0;
}