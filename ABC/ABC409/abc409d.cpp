// https://atcoder.jp/contests/abc409/tasks/abc409_d

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

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int del = N, ins = N;
    bool bot = false;

    rep(i, N) {
        if (bot && S[del] - 'a' < S[i] - 'a') {
            ins = i;
            break;
        }
        if (!bot && (i < N-1) && (S[i] - 'a') > (S[i + 1] - 'a')) {
            del = i;
            bot = true;
        }
    }

    rep(i, N + 1) {
        if (i < del) cout << S[i];
        else if (i == del) continue;
        else if (i > del && i < ins) cout << S[i];
        else if (i == ins) cout << S[del];
        else cout << S[i-1];
    }

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;

    while (T > 0) {
        T--;

        solve();
    }
    return 0;
}