// https://atcoder.jp/contests/abc454/tasks/abc454_d

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

int T;

void solve() {
    string A, B;
    cin >> A >> B;
    int lenA = A.size(), lenB = B.size();

    string memoA, memoB;
    for (int i = 0;i < lenA;i++) {
        memoA.push_back(A[i]);

        while (memoA.size() >= 4 && memoA[memoA.size() - 4] == '(' && memoA[memoA.size() - 3] == 'x' && memoA[memoA.size() - 2] == 'x' && memoA[memoA.size() - 1] == ')') {
            rep(j, 4) memoA.pop_back();
            memoA += "xx";
        }
    }
    for (int i = 0;i < lenB;i++) {
        memoB.push_back(B[i]);

        while (memoB.size() >= 4 && memoB[memoB.size() - 4] == '(' && memoB[memoB.size() - 3] == 'x' && memoB[memoB.size() - 2] == 'x' && memoB[memoB.size() - 1] == ')') {
            rep(j, 4) memoB.pop_back();
            memoB += "xx";
        }
    }

    if (memoA == memoB) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> T;
    while (T > 0) {
        T--;

        solve();
    }
    return 0;
}