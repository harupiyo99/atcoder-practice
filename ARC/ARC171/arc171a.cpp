// https://atcoder.jp/contests/arc171/tasks/arc171_a
// 最初、1行目にルークを配置する前提で始まっていたせいか、テストケースが通らずACできませんでした。
// (N + 1) / 2を候補にすることで、1行目にポーンを配置するケースでも落ちないことに気が付き、ACできました。

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
using vvi = vector<vector<int>>; 
using msi = map<string, int>;

int main()
{
    ll T;
    cin >> T;
    
    for (ll i = 0;i < T;i++) {
        ll N,A,B;
        cin >> N >> A >> B;

        ll tate = min(N - A, (N + 1) / 2);
        if (N >= A && tate * (N - A) >= B) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}