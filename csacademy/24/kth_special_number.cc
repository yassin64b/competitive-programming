#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int K;
    cin >> K;
    for (int i = 1, cnt = 0; ; ++i) {
        bool flag = true;
        for (int j = 1; j <= i; j <<= 1) {
            if ((i & j) && (i & (j << 1))) {
                flag = false;
            }
        }
        if (flag) {
            ++cnt;
        }
        if (cnt == K) {
            cout << i << "\n";
            return 0;
        }
    }
    
    return 0;
}