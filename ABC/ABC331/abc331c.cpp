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

    int N;
    cin >> N;
    vi A(N),B(N); // Aはsortしない
    for (int i = 0;i < N;i++) {
        cin >> A[i];
        B[i] = A[i];
    }

    sort(B.begin(),B.end());
    vll sum(N);
    sum[0] = B[0];
    for (int i = 1;i < N;i++) sum[i] = sum[i - 1] + B[i];

    for (int i = 0;i < N;i++) {
        auto it = upper_bound(B.begin(),B.end(),A[i]);
        int num = distance(B.begin(), it) - 1;

        if (i == N - 1) cout << sum[N - 1] - sum[num] << "\n";
        else cout << sum[N - 1] - sum[num] << " ";
    }
    return 0;
}