// https://atcoder.jp/contests/abc424/tasks/abc424_c

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
    
    int N;
    cin >> N;
    vi A(N), B(N);
    vvi graph(N);
    vector<bool> skill(N, false);
    for (int i = 0;i < N;i++) {
        cin >> A[i] >> B[i];
        if (A[i] == 0 && B[i] == 0) skill[i] = true;
        else {
            graph[A[i]-1].push_back(i);
            graph[B[i]-1].push_back(i);
        }
    }

    queue<int> T;
    for (int i = 0;i < N;i++) if (A[i] == 0 && B[i] == 0) T.push(i);
    while (!T.empty()) {
        int x = T.front();
        T.pop();

        for (int i : graph[x]) {
            if (!skill[i]) T.push(i);
            skill[i] = true; 
        }
    }

    int ans = 0;
    for (ll i = 0;i < N;i++) {
        if (skill[i]) ans++;
    }

    cout << ans << "\n";
    return 0;
}