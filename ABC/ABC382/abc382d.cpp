// https://atcoder.jp/contests/abc382/tasks/abc382_d

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

int N, M;

void solve() {
    vvi w = {{}};

    for (int i = 1;i <= N;i++) {
        vvi v;
        for (vi a : w) {
            for (int x = (i == 1 ? 1 : a.back() + 10); x <= M - 10 * (N - i);x++) {
                vi na = a;
                na.push_back(x);
                v.push_back(na);
            }
        }
        w = v;
    }

    int len = w.size();
    cout << len << "\n";
    for (vi x : w) {
        for (int j : x) cout << j << " ";
        cout << "\n";
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> M;

    solve();
    return 0;
}