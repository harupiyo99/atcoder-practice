// https://atcoder.jp/contests/abc444/tasks/abc444_d

#include <iostream>   
#include <vector>  
#include <algorithm>

using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vi A(N);
    for (int i = 0;i < N;i++) cin >> A[i];

    int maxA = *max_element(A.begin(), A.end());

    vi dif(maxA + 5, 0), ansnum(maxA+5, 0);
    for (int i = 0;i < N;i++) {
        dif[maxA - A[i] + 5]++;
    }
    for (int i = 0;i < maxA;i++) {
        ansnum[i+5] = ansnum[i+4] + dif[i+5];
    }

    for (int i = maxA + 4;i > 4;i--) {
        int num = ansnum[i];
        ansnum[i-5] += num / 100000;
        num -= 100000 * (num / 100000);
        ansnum[i-4] += num / 10000;
        num -= 10000 * (num / 10000);
        ansnum[i-3] += (num / 1000);
        num -= 1000 * (num / 1000);
        ansnum[i-2] += (num / 100);
        num -= 100 * (num / 100);
        ansnum[i-1] += (num / 10);
        num -= 10 * (num / 10);
        ansnum[i] = num;
    }

    bool start = false;
    for (int i = 0;i < maxA + 5;i++) {
        if (!start && ansnum[i] != 0) {
            cout << ansnum[i];
            start = true;
        } 
        else if (start) cout << ansnum[i];
    } 
    return 0;
}