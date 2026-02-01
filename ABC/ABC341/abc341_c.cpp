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
    int H,W,N;
    cin >> H >> W >> N;
    string T;
    vector<string> S(H + 1);
    cin >> T;
    for (int i = 0;i < H;i++) cin >> S[i];

    vector<pair<int,int>> Takahashi = {{0,0}};
    int maxa = 0,maxb = 0,mina = 0,minb = 0;
    for (int i = 0;i < N;i++) {
        int a = Takahashi[i].first;
        int b = Takahashi[i].second;
        if (T[i] == 'L') Takahashi.push_back(make_pair(a,b - 1));
        else if (T[i] == 'R') Takahashi.push_back(make_pair(a,b + 1));
        else if (T[i] == 'U') Takahashi.push_back(make_pair(a - 1,b));
        else if (T[i] == 'D') Takahashi.push_back(make_pair(a + 1,b));

        if (maxa < Takahashi[i + 1].first) maxa = Takahashi[i].first;
        if (maxb < Takahashi[i + 1].second) maxb = Takahashi[i].second;
        if (mina > Takahashi[i + 1].first) mina = Takahashi[i].first;
        if (minb > Takahashi[i + 1].second) minb = Takahashi[i].second;
    }

    int count = 0;

    for (int i = -mina;i <= H - maxa - 1;i++) {
        for (int j = -minb;j <= (W - maxb - 1);j++) {
            count++;
            for (int k = 0;k <= N;k++) {
                if (S[i + Takahashi[k].first][j + Takahashi[k].second] == '#') {
                    count--;
                    break;
                }
            }
        }
    }
    cout << count << "\n";
    return 0;
}
