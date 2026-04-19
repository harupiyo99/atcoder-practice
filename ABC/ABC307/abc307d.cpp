// https://atcoder.jp/contests/abc307/tasks/abc307_d

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
string S;

void solve() {
    string ans;
    int c = 0; //そこまでのかっこの数

    for (int i = 0;i < N;i++) {
        if (S[i] == '(') {
            c++;
            ans.push_back('(');
        }
        else if (S[i] ==')') {
            ans.push_back(S[i]);

            if (c != 0) {
                while (!ans.empty()) {
                    if (ans.back() == '(') {
                        ans.pop_back();
                        c--;
                        break;
                    }
                    ans.pop_back();
                }
            }
        }
        else {
            ans.push_back(S[i]);
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> N >> S;

    solve();
    return 0;
}