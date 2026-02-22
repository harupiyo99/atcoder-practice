// https://atcoder.jp/contests/abc302/tasks/abc302_c
// Sをソートし忘れていたため、WAが出た。
// 文字列の配列であっても、ソートすべきだと学んだ。

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
using ll = long long int;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vector<int>>; 
using pii = pair<int,int>;
using psi = pair<string,int>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N,M;
    cin >> N >> M;
    vs S(N);
    for (int i = 0;i < N;i++) {
        cin >> S[i];
    }
    sort(S.begin(),S.end());

    bool ans = false;
    do {
        bool judge = true;
        for (int i = 0;i < N - 1;i++) {
            int diff = 0;
            for (int j = 0;j < M;j++) {
                if (S[i][j] != S[i + 1][j]) diff++;
            }
            if (diff != 1) {
                judge = false;
                break;
            }
        }
        if (judge) {
            ans = true;
            break;
        }
    } while (next_permutation(S.begin(),S.end()));

    if (ans) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}