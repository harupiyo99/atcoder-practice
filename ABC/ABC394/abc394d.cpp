// https://atcoder.jp/contests/abc394/submissions/74545527

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
    string S;
    cin >> S;
    int N = S.size();

    stack<char> memo;
    string ans = "Yes\n";
    rep(i, N) {
        if (S[i] == '(' || S[i] == '[' || S[i] == '<') memo.push(S[i]);
        else if (!memo.empty() && (S[i] == ')' && memo.top() == '(') || (S[i] == ']' && memo.top() == '[') || (S[i] == '>' && memo.top() == '<')) memo.pop();
        else {
            ans = "No\n";
            break;
        }
    }

    if (!memo.empty()) ans = "No\n";
    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    solve();
    return 0;
}