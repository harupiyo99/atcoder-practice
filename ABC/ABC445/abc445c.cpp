// https://atcoder.jp/contests/abc445/tasks/abc445_c

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
using vvi = vector<vector<int>>; 
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll N;
    cin >> N;
    vector<ll> A(N);
    for (ll i = 0;i < N;i++) {
        cin >> A[i];
        A[i]--;
    }

    vector<ll> ans(N,-1);

    for (int i = 0;i < N;i++) {
        if (ans[i] != -1) continue;
        else {
            ll inans = i;
            vector<ll> reached;
            while (inans != A[inans] && ans[inans] == -1) {
                reached.push_back(inans);
                inans = A[inans];
            }
            reached.push_back(inans);

            for (ll j = 0;j < reached.size();j++) {
                if (ans[inans] == -1) {
                    ans[reached[j]] = A[inans] + 1;
                }
                else ans[reached[j]] = ans[inans];
            }
        }
    }

    for (ll i = 0;i < N;i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}