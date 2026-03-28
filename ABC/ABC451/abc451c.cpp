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

    priority_queue<ll, vll, greater<ll>> tree;
    ll num = 0;
    while (Q > 0) {
        Q--;

        ll n, h;
        cin >> n >> h;

        if (n == 1) {
            tree.push(h);
            num++;
        }
        else {
            ll min;
            if (!tree.empty()) min = tree.top();
            while (min <= h && !tree.empty()) {
                tree.pop();

                num--;
                if (!tree.empty()) min = tree.top();
            }
        }

        cout << num << "\n";
    }
    return 0;
}