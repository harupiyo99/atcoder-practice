// https://atcoder.jp/contests/abc444/submissions/me
// Lが高々２個しかないことには気が付いたが、判定方法でif文を多用しすぎて、WAが取れなかった。
// Lの値を投げて、それが適切か判定する関数を作る方針にしたほうがよかったと考える。また、for+ifがセットで出てくるときは、whileを使うべきだと考えた。

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>       
#include<queue>
#include<cmath>
#include<iomanip>
#include<set>

using namespace std;
using ll = long long int;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vector<int>>; 
using pii = pair<int,int>;
using psi = pair<string,int>;
using msi = map<string, int>;

bool check(ll L, ll N, const vector<ll>& A) {
    ll left = 0;
    ll right = N - 1;

    while (left <= right) {
        if (A[right] == L) {
            right--;
        }
        else if (left < right && A[left] + A[right] == L) {
            left++;
            right--;
        }
        else return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0;i < N;i++) {
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    vector<ll> ans;
    if (check(A[N - 1],N,A)) ans.push_back(A[N - 1]);
    if (check(A[N - 1] + A[0],N,A)) ans.push_back(A[N - 1] + A[0]);
    sort(ans.begin(),ans.end());
    if (ans.size() == 2 && ans[1] == ans[2]) ans.erase(ans.begin() + 1);
    for (int i = 0;i < ans.size();i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}