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
    
    int N;
    cin >> N;
    int a,b,c;
    a = N / 100;
    b = (N - a * 100) / 10;
    c = (N - a * 100 - b * 10);
    if ((a == b) && (b == c)) cout << "Yes" << "\n";
    else cout << "No" << "\n";
    return 0;
}