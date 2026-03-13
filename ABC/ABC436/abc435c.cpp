#include <iostream>   
#include <vector>    
#include <algorithm>
#include <utility> 
#include <set>

using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>; 
using vvll = vector<vector<ll>>;
using pii = pair<int, int>;
using pis = pair<int, string>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll N;
    int M;
    cin >> N >> M;

    set<pair<ll, ll>> tile;
    for (int i = 0;i < M;i++) {
        ll R, C;
        cin >> R >> C;
        if (tile.count({R,C}) == 0 && tile.count({R+1, C}) == 0 && tile.count({R, C+1}) == 0 && tile.count({R+1, C+1}) == 0) {
            tile.insert(make_pair(R, C));
            tile.insert(make_pair(R+1, C));
            tile.insert(make_pair(R, C+1));
            tile.insert(make_pair(R+1, C+1));
        }
    }

    cout << (ll)(tile.size()) / 4 << "\n";
    return 0;
}