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
    int cnt = 0, mx = 0;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x == 1) {
            ++cnt;
        } else {
            cnt = max(0, cnt-1);
        }
        mx = max(mx, cnt);
    }
    cout << mx << "\n";
    
    return 0;
}