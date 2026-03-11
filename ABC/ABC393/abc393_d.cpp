// https://atcoder.jp/contests/abc393/tasks/abc393_d

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

    vll sum0(1, 0);
    ll x = 0;
    for (ll i = 0;i < N;i++) {
        if (S[i] == '0') {
            sum0[x]++;
        }
        else {
            x++;
            sum0.push_back(sum0[x-1]);
        }
    }
    sum0.erase(sum0.begin() + x);

    ll c1 = x / 2;
    ll ans1 = 0;
    for (ll i = 0;i < x;i++) {
        ans1 += abs(sum0[i] - sum0[c1]);
    }

    ll c2 = x / 2 + 1;
    ll ans2 = 0;
    for (ll i = 0;i < x;i++) {
        ans2 += abs(sum0[i] - sum0[c2]);
    }

    cout << min(ans1, ans2) << "\n";
    return 0;
}