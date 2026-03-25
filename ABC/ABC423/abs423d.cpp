// https://atcoder.jp/contests/abc423/tasks/abc423_d

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility>
#include <tuple> 
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
    
    ll N, K;
    cin >> N >> K;
    vll A(N), B(N), C(N);
    for (ll i = 0;i < N;i++) cin >> A[i] >> B[i] >> C[i];

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> in;

    vll ans(N, -1);
    ll sum = 0;
    ll T = 0;
    for (ll i = 0;i < N;i++) {
        T = max(T, A[i]);
        while (sum + C[i] > K) {
            pair<ll, ll> q = in.top(); in.pop();
            T = max(T, q.first);
            sum -= q.second;
        }

        ans[i] = T;
        in.push(make_pair(T + B[i], C[i]));
        sum += C[i];
    }

    for (ll i = 0;i < N;i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}