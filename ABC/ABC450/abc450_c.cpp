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

void dfs(bool& judge, ll H, ll W, ll x, ll y, vector<vector<bool>>& visited, const vs& S) {
    if (x != 0 && x != H-1 && y != 0 && y != W-1) visited[x][y] = true;
    else {
        judge = false;
        return;
    }

    if (S[x+1][y] == '.' && !visited[x+1][y]) {
        dfs(judge, H, W, x+1, y, visited, S);
    }
    if (S[x][y+1] == '.' && !visited[x][y+1]) {
        dfs(judge, H, W, x, y+1, visited, S);
    }
    if (S[x-1][y] == '.' && !visited[x-1][y]) {
        dfs(judge, H, W, x-1, y, visited, S);
    }
    if (S[x][y-1] == '.' && !visited[x][y-1]) {
        dfs(judge, H, W, x, y-1, visited, S);
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int H,W;
    cin >> H >> W;
    vs S(H);
    for (int i = 0;i < H;i++) cin >> S[i];

    vector<vector<bool>> visited(H, vector<bool>(W, false));
    ll ans = 0;

    for (ll i = 1;i < H-1;i++) for (ll j = 1;j < W-1;j++) {
        if (S[i][j] == '.' && !visited[i][j]) {
            bool judge = true;
            
            dfs(judge, H, W, i, j, visited, S);

            if (judge) {
                ans++;
            }
        }
    }

    cout << ans << "\n";
    return 0;
}