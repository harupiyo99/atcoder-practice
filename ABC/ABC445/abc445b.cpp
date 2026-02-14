// https://atcoder.jp/contests/abc445/tasks/abc445_b

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
    
    int N;
    cin >> N;
    vector<string> S(N);
    int maxS = 0;
    for (ll i = 0;i < N;i++) {
        cin >> S[i];
        int len = S[i].size();
        maxS = max(maxS, len);
    }

    for (int i = 0;i < N;i++) {
        int num = (maxS - S[i].size()) / 2;
        string Snew;
        for (int j = 0;j < num;j++) Snew.push_back('.');
        Snew += S[i];
        for (int j = 0;j < num;j++) Snew.push_back('.');

        cout << Snew << "\n";
    }
    return 0;
}