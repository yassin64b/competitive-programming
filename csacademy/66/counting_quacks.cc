#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cassert>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N, T;
    cin >> N >> T;
    vector<int> x(N);
    map<int, int> m;
    for (int i = 0; i < N; ++i) {
        cin >> x[i];
        ++m[x[i]];
    }
    
    vector<int> v(T + 1, 0);
    for (const auto &p : m) {
        for (int j = p.first; j <= T; j += p.first) {
            v[j] += p.second;
        }
    }
    
    int mx = -1;
    for (int i = 0; i <= T; ++i) {
        mx = max(mx, v[i]);
    }

    int cnt = 0;
    for (int i = 0; i <= T; ++i) {
        cnt += v[i] == mx;
    }

    cout << mx << " " << (mx == 0 ? T : cnt) << endl;
    
    return 0;
}