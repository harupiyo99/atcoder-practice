#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>       
#include<queue>
#include<cmath>
#include<iomanip>
#include<set>

using namespace std;
using ll = long long int;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vector<int>>; 
using pii = pair<int,int>;
using psi = pair<string,int>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll Q;
    cin >> Q;
    vector<ll> bag(10e6,0);
    ll kind = 0;

    for (ll i = 1;i <= Q;i++) {
        int num;
        cin >> num;

        ll x;
        if (num == 1) {
            cin >> x;
            bag[x]++;
            if (bag[x] == 1) kind++;
        }
        else if (num == 2) {
            cin >> x;
            bag[x]--;
            if (bag[x] == 0) kind--;
        }
        else cout << kind << "\n";
    }
    return 0;
}