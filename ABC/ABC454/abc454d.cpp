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

int T;

string process(string x) {
    int N = x.size();
    string ans;

    for (int i = 0;i < N;i++) {
        if (x[i] == ')') {
            int len = ans.size();
            if (len >= 3 && ans[len - 1] == 'x' && ans[len - 2] == 'x' && ans[len - 3] == '(') {
                for (int j = 0;j < 3;j++) ans.pop_back();
                for (int j = 0;j < 2;j++) ans.push_back('x');
            }
            else ans.push_back(')');
        }
        else {
            ans.push_back(x[i]);
        }
    }

    return ans;
}

void solve() {
    string A, B;
    cin >> A >> B;

    if (process(A) == process(B)) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    return;
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