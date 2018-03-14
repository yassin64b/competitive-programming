#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    int mx = 0, cur = 0;
    for (int i = 0; i < N; ++i) {
        cur += (A[i] ? -1 : 1);
        if (cur < 0) cur = 0;
        mx = max(mx, cur);
    }
    int mn = 0; cur = 0;
    for (int i = 0; i < N; ++i) {
        cur += (A[i] ? -1 : 1);
        if (cur > 0) cur = 0;
        mn = min(mn, cur);
    }
    cout << mx - mn + 1 << "\n";
    
    
    return 0;
}