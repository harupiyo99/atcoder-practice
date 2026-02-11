// https://atcoder.jp/contests/abc338/tasks/abc338_c
// 最初、0除算の場合の処理が甘くて、ランタイムエラーが起きていた。
// そこを直すと、ACできた。

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

    int N;
    cin >> N;
    vector<ll> Q(N),A(N),B(N);
    for (int i = 0;i < N;i++) cin >> Q[i];
    for (int i = 0;i < N;i++) cin >> A[i];
    for (int i = 0;i < N;i++) cin >> B[i];

    ll min = 10000000000;
    for (int i = 0;i < N;i++) {
        ll minpre;
        if (A[i] > 0) minpre = Q[i] / A[i];
        else minpre = min + 1000;

        if (minpre < min) min = minpre;
    }

    ll maxy = 0;
    for (ll i = 0;i <= min;i++) {
        ll miny = 10000000000;
        for (int j = 0;j < N;j++) {
            ll y;
            if (B[j] > 0) {
                y = (Q[j] - A[j] * i) / B[j];
            }
            else y = miny + 100;
            if (miny > y) miny = y;
        }

        if (maxy < miny + i) maxy = miny + i;
    }

    cout << maxy << "\n";
    return 0;
}