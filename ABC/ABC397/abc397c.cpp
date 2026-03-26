// https://atcoder.jp/contests/abc397/tasks/abc397_c

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
    
    int N;
    cin >> N;
    vi A(N+1);
    for (int i = 0;i < N;i++) cin >> A[i];

    set<int> cur, cur2;
    vi kind(N, 0), kind2(N, 0);
    cur.insert(A[0]);
    kind[0] = 1;
    for (int i = 1;i < N;i++) {
        if (cur.count(A[i]) == 1) kind[i] = kind[i-1];
        else {
            kind[i] = kind[i-1] + 1;
            cur.insert(A[i]);
        }
    }
    kind2[N-1] = 1;
    cur2.insert(A[N-1]);
    for (int i = N-2;i >= 0;i--) {
        if (cur2.count(A[i]) == 1) kind2[i] = kind2[i+1];
        else {
            kind2[i] = kind2[i+1] + 1;
            cur2.insert(A[i]);
        }
    }

    int ans = 0;
    for (int i = 0;i < N-1;i++) {
        ans = max(ans, kind[i] + kind2[i+1]);
    }

    cout << ans << "\n";
    return 0;
}