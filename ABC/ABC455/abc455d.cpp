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

int N, Q;
vi C, P;

void solve() {
    vi up(2 * N), down(2 * N);

    for (int i = 0;i < N;i++) {
        down[i] = N + i;
        up[i] = -1;
        up[N + i] = i;
        down[N + i] = -1;
    }
    for (int i = 0;i < Q;i++) {
        int D = down[C[i]];

        down[C[i]] = P[i];
        up[P[i]] = C[i];
        up[D] = -1;
    }

    for (int i = 0;i < N;i++) {
        int cnt = 0;

        int cur = N + i;
        while (up[cur] != -1) {
            cur = up[cur];
            cnt++;
        }

        cout << cnt << " ";
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;
    C.resize(Q);
    P.resize(Q);
    for (int i = 0;i < Q;i++) {
        cin >> C[i] >> P[i];
        C[i]--;
        P[i]--;
    }
    
    solve();
    return 0;
}