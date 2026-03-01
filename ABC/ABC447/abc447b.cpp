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
    
    string S;
    cin >> S;

    mii memo;
    for (int i = 0;i < S.size();i++) {
        memo[S[i]]++;
    }

    string log;
    int maxn = 0;
    for (int i = 0;i <= 25;i++) {
        maxn = max(memo['a' + i], maxn);
    }
    for (int i = 0;i <= 25;i++) {
        if (maxn == memo['a' + i]) {
            log.push_back('a' + i);
        }
    }

    int len = log.size();
    for (int i = 0;i < len;i++) {
        S.erase(remove(S.begin(), S.end(), log[i]), S.end());
    }
    cout << S << "\n";
    return 0;
}