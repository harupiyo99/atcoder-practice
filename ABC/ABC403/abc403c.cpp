#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>
#include <set>

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
    
    int N, M, Q;
    cin >> N >> M >> Q;

    vector<set<int>> user(N);
    vector<bool> all(N, false);
    while (Q > 0) {
        Q--;

        int num, X, Y; 
        cin >> num;
        if (num == 1) {
            cin >> X >> Y;
            user[X-1].insert(Y);
        }
        else if (num == 2) {
            cin >> X;
            all[X-1] = true;
        }
        else {
            cin >> X >> Y;
            if (all[X-1] || user[X-1].count(Y) == 1) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}