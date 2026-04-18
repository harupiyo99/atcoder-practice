// https://atcoder.jp/contests/abc375/tasks/abc375_c

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

int N;
vs A;

void solve() {
    for (int x = 0;x < N;x++) {
        for (int y = 0;y < N;y++) {
            int c = min({x + 1, y + 1, (N - x), (N - y)});

            if (c % 4 == 0) cout << A[x][y];
            else if (c % 4 == 3) cout << A[y][N - 1 - x];
            else if (c % 4 == 2) cout << A[N - 1 - x][N - 1 - y];
            else cout << A[N - 1 - y][x];
        }

        cout << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);
    for (int i = 0;i < N;i++) cin >> A[i]; 
    
    solve();
    return 0;
}