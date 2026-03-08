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
    
    int N,X;
    cin >> N >> X;

    for (int i = 0;i < N;i++) {
        int A;
        cin >> A;
        if (A < X) {
            X = A;
            cout << 1 << "\n";
        }
        else cout << 0 << "\n";
    }
    return 0;
}