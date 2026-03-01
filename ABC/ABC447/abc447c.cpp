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
    
    ll ans = -1;

    string S,T;
    cin >> S >> T;

    ll lenS = S.size(),lenT = T.size();
    string Sm,Tm;
    for (ll i = 0;i < lenS;i++) {
        if (S[i] != 'A') {
            Sm.push_back(S[i]);
        }
    }
    for (ll i = 0;i < lenT;i++) {
        if (T[i] != 'A') Tm.push_back(T[i]);
    }

    ll spacead = 0, lensm = Sm.size(), lentm = Tm.size();
    ll lenm = max(lentm, lensm);
    vll Sspace(lenm + 1,0), Tspace(lenm + 1,0);
    for (ll i = 0;i < lenS;i++) {
        if (S[i] != 'A') {
            spacead++;
        }
        else Sspace[spacead]++;
    }
    spacead = 0;
    for (ll i = 0;i < lenT;i++) {
        if (T[i] != 'A') spacead++;
        else Tspace[spacead]++;
    }

    if (Sm == Tm) {
        ans = 0;
        for (int i = 0;i < lenm + 1;i++) {
            ans += abs(Sspace[i] - Tspace[i]);
        }
    }

    cout << ans << "\n";
    return 0;
}