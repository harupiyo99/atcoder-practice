// https://atcoder.jp/contests/abc406/tasks/abc406_d

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
    
    int H, W, N;
    cin >> H >> W >> N;
    vvi garbx(H), garby(W);
    rep(i, N) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;

        garbx[x].push_back(i);
        garby[y].push_back(i);
    }

    vb rem(N, false), qx(H, false), qy(W, false);

    int Q;
    cin >> Q;

    while (Q > 0) {
        Q--;

        int ans = 0;

        int n;
        cin >> n;

        if (n == 1) {
            int x;
            cin >> x;
            x--;

            if (!qx[x]) {
                for (int i : garbx[x]) if (!rem[i]) {
                    rem[i] = true;
                    ans++;
                }
                qx[x] = true;
            }
        }
        else {
            int y;
            cin >> y;
            y--;

            if (!qy[y]) {
                for (int i : garby[y]) if (!rem[i]) {
                    rem[i] = true;
                    ans++;
                }
                qy[y] = true;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}