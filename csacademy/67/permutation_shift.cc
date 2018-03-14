#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    int res = 0;
    for (int off = 0; off < N; ++off) {
        int cur = 0;
        for (int i = 0; i < N; ++i) {
            if (P[(i + off) % N] == i + 1) {
                ++cur;
            }
        }
        res = max(res, cur);
    }
    cout << res << endl;
    
    return 0;
}