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
    
    ll N,Q;
    cin >> N >> Q;
    vll A(N), Asort(N);
    for (ll i = 0;i < N;i++) {
        cin >> A[i];
        Asort[i] = A[i];
    }

    sort(Asort.begin(), Asort.end());
    for (ll i = 0;i < Q;i++) {
        int K;
        cin >> K;
        vll B(K);
        priority_queue<int, vector<int>, greater<int>> numB;
        for (ll i = 0;i < K;i++) {
            cin >> B[i];
            numB.push(A[B[i] - 1]);
        }

        priority_queue<int, vector<int>, greater<int>> T;
        for (int i = 0;i < K + 1;i++) {
            T.push(Asort[i]);
        }
        bool judge = true;
        while (!numB.empty()) {
            if (T.top() < numB.top()) {
                cout << T.top() << "\n";
                judge = false;
                break;
            }
            else {
                numB.pop();
                T.pop();
            }
        }
        if (judge) cout << T.top() << "\n";
    }
    return 0;
}