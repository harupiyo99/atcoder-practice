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
    int N,M,K;
    cin >> N >> M >> K;
    vi C(M);
    vvi A(M);
    vector<char> R(M);
    for (int i = 0;i < M;i++) {
        cin >> C[i];
        for (int j = 0;j < C[i];j++) {
            int a;
            cin >> a;
            A[i].push_back(a);
        }
        cin >> R[i];
    }
    ll ans = 0;
    
    for (int i = 0;i <= pow(2,N) - 1;i++) {

        bool apjudge = true;
        for (int j = 0;j < M;j++) {
            int count = 0;
            for (int k = 0;k < C[j];k++) {
                if (i >> (A[j][k] - 1) & 1) count++;
            }
            char judge;
            if (count < K) judge = 'x';
            else judge = 'o';

            if (judge != R[j]) {
                apjudge = false;
                break;
            }
        }
        if (apjudge) ans++;
    }
    
    cout << ans << "\n";
    return 0;
}
