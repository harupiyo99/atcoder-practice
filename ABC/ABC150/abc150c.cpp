// https://atcoder.jp/contests/abc150/submissions/me

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
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vi P(N),Q(N),numv(N);
    for (int i = 0;i < N;i++) cin >> P[i];
    for (int i = 0;i < N;i++) cin >> Q[i];
    for (int i = 0;i < N;i++) numv[i] = i + 1;

    ll count = 1,a,b;
    do {
        bool judgeP = true,judgeQ = true;

        for (int i = 0;i < N;i++) {
            if (numv[i] != P[i]) judgeP = false;
            if (numv[i] != Q[i]) judgeQ = false;
        }
        
        if (judgeP) a = count;
        if (judgeQ) b = count;

        count++;
    } while (next_permutation(numv.begin(),numv.end()));

    cout << abs(a - b) << "\n";
    return 0;
}
