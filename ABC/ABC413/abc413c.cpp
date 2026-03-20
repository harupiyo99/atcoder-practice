// https://atcoder.jp/contests/abc413/tasks/abc413_c

#include <iostream>   
#include <vector>  
#include <algorithm>
#include <utility> 
#include <queue>

using namespace std;

using ll = long long;

using vll = vector<ll>; 
using vvll = vector<vector<ll>>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll Q;
    cin >> Q;

    queue<pair<ll, ll>> A;

    while (Q > 0) {
        Q--;

        int num;
        cin >> num;

        if (num == 1) {
            ll c, x;
            cin >> c >> x;
            A.push(make_pair(c, x));
        }
        else {
            ll k;
            cin >> k;

            ll ans = 0, rem = k;
            while (rem > 0) {
                if (rem >= A.front().first) {
                    ans += A.front().second * A.front().first;
                    rem -= A.front().first;
                    A.pop();
                }
                else {
                    ans += rem * A.front().second;
                    A.front().first -= rem;
                    rem = 0;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}