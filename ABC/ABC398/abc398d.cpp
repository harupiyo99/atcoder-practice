// https://atcoder.jp/contests/abc398/tasks/abc398_d

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

int N, R, C;
string S;

void solve() {
    pii Takahashi = {R, C}, takibi = {0, 0};
    set<pii> smoke;
    smoke.insert({0, 0});

    rep(i, N) {
        int Takahashi_x = Takahashi.first, Takahashi_y = Takahashi.second;
        int takibi_x = takibi.first, takibi_y = takibi.second;

        if (S[i] == 'N') {
            Takahashi_x += 1;
            takibi_x += 1;
        }
        else if (S[i] == 'W') {
            takibi_y += 1;
            Takahashi_y += 1;
        }
        else if (S[i] == 'S') {
            takibi_x -= 1;
            Takahashi_x -= 1;
        }
        else if (S[i] == 'E') {
            takibi_y -= 1;
            Takahashi_y -= 1;
        }
        Takahashi = {Takahashi_x, Takahashi_y};
        takibi = {takibi_x, takibi_y};

        if (!smoke.count(takibi)) smoke.insert(takibi);
        if (smoke.count(Takahashi)) cout << '1';
        else cout << '0';
    }

    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> R >> C;
    cin >> S;
    
    solve();
    return 0;
}