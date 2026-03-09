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

using ll = long long;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>; 
using vvll = vector<vector<ll>>;
using vs = vector<string>;

using pii = pair<int, int>;
using pis = pair<int, string>;
using mii = map<int, int>;
using mll = map<ll, ll>;
using msi = map<string, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    char As,Bs,Cs,Ds;
    cin >> As >> Bs >> Cs >> Ds;
    int A = As - '0', B = Bs - '0', C = Cs - '0', D = Ds - '0'; 

    char op1, op2, op3;
    for (int i = 0;i < 8;i++) {
        int num = i;
        if (i / 4 == 1) {
            op3 = '+';
            num -= 4;
        }
        else op3 = '-';

        if (num / 2 == 1) {
            op2 = '+';
            num -= 2;
        }
        else op2 = '-';

        if (num == 1) {
            op1 = '+';
        }
        else op1 = '-';

        int ans = A;
        if (op1 == '+') ans += B;
        else ans -= B;
        if (op2 == '+') ans += C;
        else ans -= C;
        if (op3 == '+') ans += D;
        else ans -= D;

        if (ans == 7) {
            cout << A << op1 << B << op2 << C << op3 << D << "=7\n";
            break;
        }
    }
    return 0;
}