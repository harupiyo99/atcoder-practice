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

    ll N,M;
    cin >> N >> M;
    vector<ll> A(N),B(M);
    for (ll i = 0;i < N;i++) cin >> A[i];
    for (ll i = 0;i < M;i++) cin >> B[i];

    vector<ll> check(1,0);
    ll min = A[0];
    for (ll i = 1;i < N;i++) {
        if (A[i] < min) {
            min = A[i];
            check.push_back(i);
        }
    }
    
    ll len = check.size();
    for (ll i = 0;i < M;i++) {
        if (B[i] < min) cout << -1 << "\n";

        else {
            ll ans_index;
            ll left = 0,right = len - 1,mid;
            while (left <= right) {
                mid = (left + right) / 2;
                if (B[i] < A[check[mid]]) {
                    left = mid + 1;
                }
                else if (B[i] >= A[check[mid]]) {
                    ans_index = check[mid];
                    right = mid - 1;
                } 
            }
            cout << ans_index + 1 << "\n";
        }
    }
    return 0;
}