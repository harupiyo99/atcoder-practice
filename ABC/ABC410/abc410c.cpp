#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <stack>
#include <queue>
#include <cmath>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

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
    
    ll N, Q;
    cin >> N >> Q;

    vll A(N);
    for (ll i = 0;i < N;i++) A[i] = i+1;

    ll cur = 0;
    while (Q > 0) {
        Q--;

        int num;
        cin >> num;

        if (num == 1) {
            ll p, x;
            cin >> p >> x;
            A[(cur + (p-1)) % N] = x;
        }
        else if (num == 2) {
            ll p;
            cin >> p;
            cout << A[(cur + (p-1)) % N] << "\n";
        }
        else {
            ll k;
            cin >> k;
            cur = (cur + k) % N;
        }
    } 
    return 0;
}