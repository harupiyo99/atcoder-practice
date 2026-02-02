// https://atcoder.jp/contests/abc384/tasks/abc384_c

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
    int a,b,c,d,e;
    cin >> a >> b >> c >> d >> e;

    msi part;
    for (int i = 1;i <= 31;i++) {
        int ej = i / 16;
        int dj = (i - ej * 16) / 8;
        int cj = (i - ej * 16 - 8 * dj) / 4;
        int bj = (i - ej * 16 - 8 * dj - 4 * cj) / 2;
        int aj = (i - ej * 16 - 8 * dj - 4 * cj - 2 * bj);

        string key;
        int score = 0;
        if (aj == 1) {
            key.push_back('A');
            score += aj * a;
        }
        if (bj == 1) {
            key.push_back('B');
            score += bj * b;
        }
        if (cj == 1) {
            key.push_back('C');
            score += cj * c;
        }
        if (dj == 1) {
            key.push_back('D');
            score += dj * d;
        }
        if (ej == 1) {
            key.push_back('E');
            score += ej * e;
        }
        part[key] = score;  
    }

    vector<pair<string, int>> v(part.begin(), part.end());
    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second;
        else return a.first < b.first;
    });

    for (auto& [key, value] : v) {
        cout << key << "\n";
    }
    return 0;
}
