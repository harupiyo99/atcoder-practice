// https://atcoder.jp/contests/abc421/tasks/abc421_c
// 最終状態(A,Bが交互に並んでいる状態)から逆算するという発想まではたどり着けたが、上手い逆算の方法が思いつかなかった。

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
    
    ll N;
    cin >> N;
    string S;
    cin >> S;

    ll sum1 = 0, sum2 = 0, k = -1;
    for (ll i = 0;i < 2 * N;i++) {
        if (S[i] == 'A') {
            k++;
            
            sum1 += abs(i + 1 - (2 * k + 1));
            sum2 += abs(i + 1 - 2 * (k + 1));
        }
    }

    cout << min(sum1,sum2) << "\n";
    return 0;
}