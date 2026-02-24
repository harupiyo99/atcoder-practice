// https://atcoder.jp/contests/abc267/tasks/abc267_c

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
using vll = vector<ll>;
using vvll = vector<vector<ll>>;

using pii = pair<int,int>;
using psi = pair<string,int>;
using mii = map<int, int>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 入力
    int N,M;
    cin >> N >> M;
    vi A(N);
    for (int i = 0;i < N;i++) {
        cin >> A[i];
    }

    // 累積和の計算
    vll sumA(N + 1);
    sumA[0] = 0;
    sumA[1] = A[0];
    for (int i = 2;i <= N;i++) {
        sumA[i] = sumA[i - 1] + A[i - 1];
    }
    ll sumB = A[0];
    for (int i = 1;i < M;i++) {
        sumB += (ll)(i + 1) * A[i];
    }

    ll ans = sumB;
    for (int i = 0;i < N - M;i++) {
        sumB += (ll)M * A[M + i] - (sumA[M + i] - sumA[i]);
        ans = max(sumB,ans);
    }

    cout << ans << "\n";
    return 0;
}