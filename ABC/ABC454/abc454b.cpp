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

void solve() {
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M;
    cin >> N >> M;
    
    vi fuku(M, 0), F(N);
    set<int> c;
    bool judge1 = true, judge2 = true;
    for (int i = 0;i < N;i++) {
        cin >> F[i];
        F[i]--;
        if (c.count(F[i])) judge1 = false;
        c.insert(F[i]);

        fuku[F[i]]++;
    }

    for (int i = 0;i < M;i++) if (fuku[i] == 0) judge2 = false;

    if (judge1) cout << "Yes" << "\n";
    else cout << "No" << "\n";

    if (judge2) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}