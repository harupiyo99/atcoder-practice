// https://atcoder.jp/contests/abc428/tasks/abc428_c

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>       
#include<queue>
#include<cmath>
#include<iomanip>

using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>; 
using vvll = vector<vector<ll>>;
using vs = vector<string>;

using pii = pair<int, int>;
using pis = pair<int, string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;

    vi A(1, 0), minA(1, 0);
    int len = 0;
    for (ll i = 0;i < Q;i++) {
        int num;
        cin >> num;

        if (num == 1) {
            char c;
            cin >> c;

            int a;
            if (c == '(') a = A[len] + 1;
            else a = A[len] - 1;

            A.push_back(a);
            minA.push_back(min(minA[len], a));
            len++;
        }
        else {
            A.erase(A.begin() + len);
            minA.erase(minA.begin() + len);
            len--;
        }

        if (A[len] == 0 && minA[len] == 0) cout << "Yes\n";
        else cout << "No\n"; 
    }
    return 0;
}