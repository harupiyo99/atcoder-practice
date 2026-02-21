// https://atcoder.jp/contests/abc446/tasks/abc446_b

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

    int N,M;
    cin >> N >> M;
    vi L(N);
    vvi X(N);
    for (int i = 0;i < N;i++) {
        cin >> L[i];
        for (int j = 0;j < L[i];j++) {
            int x;
            cin >> x;
            X[i].push_back(x);
        }
    }

    vi water(M + 1,1);
    vi choice(N,0);
    for (int i = 0;i < N;i++) {
        for (int j = 0;j < L[i];j++) {
            if (water[X[i][j]] == 1) {
                choice[i] = X[i][j];
                water[X[i][j]] = 0;
                break;
            }
        }
    }

    for (int i = 0;i < N;i++) cout << choice[i] << "\n";
    return 0;
}
