// https://atcoder.jp/contests/abc357/tasks/abc357_c

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
    
    vector<vs> kar(7);
    kar[0] = {"#"};
    for (int i = 1;i < 7;i++) {
        int side = 1;
        for (int j = 1;j <= i;j++) side *= 3;

        for (int j = 0;j < 3;j++) {
            if (j != 1) {
                for (int k = 0;k < side / 3;k++) {
                    kar[i].push_back({kar[i-1][k] + kar[i-1][k] + kar[i-1][k]});
                }
            }
            else {
                vs white(side / 3);
                for (int n = 0;n < side / 3;n++) {
                    for (int o = 0;o < side / 3;o++) {
                        white[n].push_back('.');
                    }
                }
                for (int k = 0;k < side / 3;k++) {
                    kar[i].push_back({kar[i-1][k] + white[k] + kar[i-1][k]});
                }
            }
        }
    }

    int N;
    cin >> N;
    int side2 = 1;
    for (int i = 1;i <= N;i++) side2 *= 3;

    for (int i = 0;i < side2;i++) cout << kar[N][i] << "\n";
    return 0;
}