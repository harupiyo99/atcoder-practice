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
    
    int H, W;
    cin >> H >> W;

    if (H == 1 && W == 1) {
        cout << 0 << "\n";
        return 0;
    }
    if (H == 1 && W != 1) {
        rep(i, W) {
            if (i == W - 1 || i == 0) cout << 1 << " "; 
            else cout << 2 << " ";
        }
        return 0;
    } 
    if (H != 1 && W == 1) {
        rep(i, H) {
            if (i == H - 1 || i == 0) cout << 1 << "\n"; 
            else cout << 2 << "\n";
        }
        return 0;
    } 

    rep(i, H) {
        rep(j, W) {
            if ((i == 0 && j == 0) || (i == 0 && j == W - 1) || (i == H - 1 && j == 0) || (i == H - 1 && j == W - 1)) cout << 2 << " ";
            else if (i == 0 || j == 0 || i == H - 1 || j == W - 1) cout << 3 << " ";
            else cout << 4 << " ";
        }
        cout << "\n";
    }
    return 0;
}