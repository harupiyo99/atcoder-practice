// https://atcoder.jp/contests/abc445/tasks/abc445_c
// 最初は前からやっていきましたが、後ろからやっていったほうが効率的だったため、後ろから処理していく解法に変更しました。

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
    
    int N;
    cin >> N;
    vi A(N);
    for (int i = 0;i < N;i++) {
        cin >> A[i];
        A[i]--;
    }

    vi ans(N);
    for (int i = N - 1;i >= 0;i--) {
        if (i == A[i]) ans[i] = i;
        else ans[i] = ans[A[i]];
        ans[i]++;
    }

    for (int i = 0;i < N - 1;i++) {
        cout << ans[i] << " ";
    }
    cout << ans[N - 1] << "\n";
    return 0;
}