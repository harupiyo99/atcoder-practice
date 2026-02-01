// https://atcoder.jp/contests/abc342/tasks/abc342_c

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
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll Q;
    cin >> Q;
    string testS = "abcdefghijklmnopqrstuvwxyz";
    string testS2 = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 1;i <= Q;i++) {
        char c,d;
        cin >> c >> d;
        for (int j = 0;j < 26;j++) {
            if (testS[j] == c) testS[j] = d;
        }
    }

    for (int i = 0;i < N;i++) {
        int index = S[i] - 'a';
        S[i] = testS[index];
    }
    cout << S << "\n";
    return 0;
}
