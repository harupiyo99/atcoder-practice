// https://atcoder.jp/contests/abc349/editorial/9779
// 最初大文字小文字の変換を忘れていてサンプルケースが通らなかった。それを直してAC。

#include <iostream>   
#include <vector>    
#include <string>    
#include <algorithm>
#include <utility> 
#include <map>       
#include<queue>
#include<cmath>
#include<iomanip>
#include<cctype>

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

    string S,T;
    cin >> S >> T;
    ll len = S.size();
    
    string ans = "No";

    ll start2 = 0;
    bool judge1 = false;
    for (ll i = 0;i < len;i++) {
        if (T[0] == (char)toupper(S[i])) {
            start2 = i + 1;
            judge1 = true;
            break;
        }
    }

    ll start3;
    bool judge2 = false;
    if (judge1) {
        for (ll i = start2;i < len;i++) {
            if (T[1] == (char)toupper(S[i])) {
                start3 = i + 1;
                judge2 = true;
                break;
            }
        }
    }

    bool judge3 = false;
    if (judge2) {
        if (T[2] == 'X') ans = "Yes";
        else {
            for (ll i = start3;i < len;i++) {
                if (T[2] == (char)toupper(S[i])) {
                    ans = "Yes";
                    break;
                }
            }
        }
    }

    cout << ans << "\n";
    return 0;
}