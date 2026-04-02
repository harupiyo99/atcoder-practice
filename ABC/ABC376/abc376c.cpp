// https://atcoder.jp/contests/abc376/tasks/abc376_c

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

ll solve() {
    ll N;
    cin >> N;
    vll A(N), B(N-1), Bsort(N-1);
    for (ll i = 0;i < N;i++) cin >> A[i];
    for (ll i = 0;i < N-1;i++) {
        cin >> B[i];
        Bsort[i] = B[i];
    }

    sort(A.begin(), A.end());
    Bsort.push_back(A[N-1]);
    sort(Bsort.begin(), Bsort.end());
    for (ll i = 0;i < N;i++) if (A[i] > Bsort[i]) return -1;

    ll x, l = A[0], r = A[N-1], mid, ans = -1;
    while (l <= r) {
        Bsort = B;
        mid = (l + r) / 2;

        Bsort.push_back(mid);
        sort(Bsort.begin(), Bsort.end());

        bool judge = true;
        for (ll i = 0;i < N;i++) if (A[i] > Bsort[i]) judge = false;

        if (judge) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cout << solve(); 
    return 0;
}