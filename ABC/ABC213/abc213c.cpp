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

    map<ll, ll> C,D;
    ll numA = 1, numB = 1;
    C[Asort[0]] = numA;
    D[Bsort[0]] = numB;
    for (ll i = 1;i < N;i++) {
        if (Asort[i] != Asort[i - 1]) {
            numA++;
            C[Asort[i]] = numA;
        }
        if (Bsort[i] != Bsort[i - 1]) {
            numB++;
            D[Bsort[i]] = numB;
        }  
    }

    for (int i = 0; i < N; i++) {
        cout << C[A[i]] << " " << D[B[i]] << "\n";
    }
    return 0;
}