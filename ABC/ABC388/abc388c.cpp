// https://atcoder.jp/contests/abc388/tasks/abc388_c
// lower_boundがイテレータであることを知らず数値型で扱い、コンパイルエラーが起きました。
// ポインタから整数に直すと、ACしました。

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
using lli = long long int;
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

    lli N;
    cin >> N;
    vector<lli> A(N + 1);
    for (lli i = 1;i <= N;i++) cin >> A[i];

    lli count = 0;
    for (lli i = N;i >= 2;i--) {
        lli border = A[i] / 2;
        auto itborder = upper_bound(A.begin(),A.end(),border);
        lli ricecakenum = distance(A.begin(), itborder) - 1;
        count += ricecakenum;
    }

    cout << count << "\n";
    return 0;
}
