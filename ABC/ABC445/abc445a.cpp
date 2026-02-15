// https://atcoder.jp/contests/abc445/tasks/abc445_a
// S.front(),S.back()によって最初と最後にアクセスできることを知り、こちらに変えた。

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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    if (S.front() == S.back()) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}