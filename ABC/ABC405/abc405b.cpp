#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <iomanip>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

using ll = long long;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>; 
using vvll = vector<vector<ll>>;
using vb = vector<bool>;
using vvb = vector<vector<bool>>;
using vs = vector<string>;

using pii = pair<int, int>;
using pis = pair<int, string>;
using pll = pair<ll, ll>;
using pls = pair<ll, string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using msi = map<string, int>;

int N, M;
vi A, countA;

void solve() {
    countA.assign(M, 0);
    for (ll i = 0;i < N;i++) {
        countA[A[i]]++;
    }

    for (ll i = 0;i < M;i++) if (countA[i] == 0) {
        cout << 0 << "\n";
        return;
    }

    for (ll i = N-1;i >= 0;i--) {
        countA[A[i]]--;

        if (countA[A[i]] == 0) {
            cout << (N-i) << "\n";
            return;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    A.resize(N);
    for (int i = 0;i < N;i++) {
        cin >> A[i];
        A[i]--;
    }
    
    solve();
    return 0;
}