// https://atcoder.jp/contests/abc381/tasks/abc381_c
// 最初、S[i - j] == 1と数字で比較していたので、WAでした。文字'1'にしたら、ACしました。

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

    ll N;
    cin >> N;
    string S;
    cin >> S;

    vector<ll> slashlog;
    for (ll i = 0;i < N;i++) {
        if (S[i] == '/') {
            slashlog.push_back(i);
        }
    }

    ll max = 1;
    for (ll &i : slashlog) {
        ll j = 1;
        while ((S[i - j] == '1') && (S[i + j] == '2') && (i - j >= 0) && (i + j < N)) {
            j++;
        }
        if (2 * (j - 1) + 1 > max) max = 2 * (j - 1) + 1;
    }

    cout << max << "\n";
    return 0;
}