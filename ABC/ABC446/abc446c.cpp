// https://atcoder.jp/contests/abc446/tasks/abc446_c

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

    ll T;
    cin >> T;

    for (ll i = 0;i < T;i++) {
        ll N,D;
        cin >> N >> D;
        vi A(N),B(N);
        for (ll j = 0;j < N;j++) {
            cin >> A[j];
        }
        for (ll j = 0;j < N;j++) {
            cin >> B[j];
        }

        queue<int> eggs;
        for (ll j = 0;j < N;j++) {
            for (int k = 0;k < A[j];k++) eggs.push(j);
            for (int k = 0;k < B[j];k++) eggs.pop();
            while ((!eggs.empty()) && (eggs.front() == j - D)) eggs.pop();
        }
        cout << ((ll)(eggs.size())) << "\n";
    }
    return 0;
}