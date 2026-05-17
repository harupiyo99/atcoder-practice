// https://atcoder.jp/contests/abc395/tasks/abc395_d

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
vi bl, lb, pb;

void solve() {
    int n, a, b;
    cin >> n >> a;
    a--;

    if (n == 1) {
        cin >> b;
        b--;

        pb[a] = lb[b];
    }
    else if (n == 2) {
        cin >> b;
        b--;

        int boxa = lb[a], boxb = lb[b];
        lb[b] = boxa;
        lb[a] = boxb;

        bl[boxa] = b;
        bl[boxb] = a;
    }
    else {
        cout << bl[pb[a]] + 1 << "\n";
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> Q;

    bl.resize(N);
    lb.resize(N);
    pb.resize(N);

    rep(i, N) {
        bl[i] = i;
        lb[i] = i;
        pb[i] = i;
    }
    
    while (Q > 0) {
        Q--;
        
        solve();
    }
    return 0;
}