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
    vector<int> v(N);
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
        cnt += v[i];
    }
    for (int i = 1; i < N; ++i) {
        v[i] += v[i-1];
    }
    
    int res = 1000*1000*1000;
    for (int i = 0; i+cnt-1 < N; ++i) {
        //start black marbles here
        int cur = v[i+cnt-1] - (i-1 >= 0 ? v[i-1] : 0);
        res = min(res, cnt - cur);
    }
    for (int i = N-cnt+1; i < N; ++i) {
        int cur = v[N-1] - (i-1 >= 0 ? v[i-1] : 0);
        //cout << i << " " << cur << "+" << v[(i+cnt-1) % N] << endl;
        cur += v[(i+cnt-1) % N];
        res = min(res, cnt - cur);
    }
    
    cout << res << "\n";
    
    return 0;
}