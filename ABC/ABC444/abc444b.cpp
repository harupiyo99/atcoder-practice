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
    ll N,K;
    cin >> N >> K;
    ll count = 0;
    for (ll i = 1;i <= N;i++) {
        ll a,b,c,d,e;
        a = i / 10000;
        b = (i - 10000 * a) / 1000;
        c = (i - 10000 * a - 1000 * b) / 100;
        d = (i - 10000 * a - 1000 * b - 100 * c) / 10;
        e = (i - 10000 * a - 1000 * b - 100 * c - 10 * d);
        if (a + b + c + d + e == K) count++;
    }
    cout << count << "\n";
    return 0;
}