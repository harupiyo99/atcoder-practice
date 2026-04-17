// https://atcoder.jp/contests/abc374/tasks/abc374_d

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

int N;
double T, S;
vector<double> A, B, C, D;

double ans;

void solve() {

    vi order;
    for (int i = 0;i < N;i++) order.push_back(i);

    ans = 100000000;
    do {
        for (int i = 0;i < (1 << N);i++) {
            pair<double, double> cur = {0, 0};
            double dist = 0;

            int n = i;
            for (int j = N - 1;j >= 0;j--) {
                if (n / (1 << j) == 1) {
                    dist += sqrt((C[order[j]] - cur.first) * (C[order[j]] - cur.first) + (D[order[j]] - cur.second) * (D[order[j]] - cur.second));
                    cur = {A[order[j]], B[order[j]]};
                    n -= (1 << j);
                }
                else {
                    dist += sqrt((A[order[j]] - cur.first) * (A[order[j]] - cur.first) + (B[order[j]] - cur.second) * (B[order[j]] - cur.second));
                    cur = {C[order[j]], D[order[j]]};
                }
            }

            ans = min(ans, dist);
        }
    } while (next_permutation(order.begin(), order.end()));

    double lin = 0;
    for (int i = 0;i < N;i++) {
        lin += sqrt((A[i] - C[i]) * (A[i] - C[i]) + (B[i] - D[i]) * (B[i] - D[i]));
    }
    lin /= T;
    ans /= S;

    ans += lin;

    cout << fixed << setprecision(8) << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> S >> T;

    A.resize(N);
    B.resize(N);
    C.resize(N);
    D.resize(N);
    for (int i = 0;i < N;i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    
    solve();
    return 0;
}