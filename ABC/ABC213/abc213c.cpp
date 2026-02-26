// https://atcoder.jp/contests/abc213/tasks/abc213_c

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
    
    ll H, W, N;
    cin >> H >> W >> N;
    vll A(N),B(N),Asort,Bsort;
    for (ll i = 0;i < N;i++) {
        cin >> A[i] >> B[i];
    }

    Asort = A;
    Bsort = B;
    sort(Asort.begin(),Asort.end());
    sort(Bsort.begin(),Bsort.end());

    Asort.erase(unique(Asort.begin(), Asort.end()), Asort.end());
    Bsort.erase(unique(Bsort.begin(), Bsort.end()), Bsort.end());

    for (int i = 0; i < N; i++) {
        ll row = lower_bound(Asort.begin(), Asort.end(), A[i]) - Asort.begin() + 1;
        ll col = lower_bound(Bsort.begin(), Bsort.end(), B[i]) - Bsort.begin() + 1;
        cout << row << " " << col << "\n";
    }
    return 0;
}