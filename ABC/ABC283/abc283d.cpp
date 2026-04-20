// https://atcoder.jp/contests/abc283/tasks/abc283_d

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

string S;
int N;

void solve() {
    set<char> box;
    string memo;

    for (int i = 0;i < N;i++) {
        memo.push_back(S[i]);

        if (S[i] == ')') {
            memo.pop_back();

            while (!memo.empty() && memo.back() != '(') {
                box.erase(memo.back());
                memo.pop_back();
            }
            if (!memo.empty()) memo.pop_back();
        }
        else if (S[i] != '(') {
            if (box.count(S[i])) {
                cout << "No" << "\n";
                return;
            }
            else {
                box.insert(S[i]);
            }
        }
    }

    cout << "Yes" << "\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();
    
    solve();
    return 0;
}