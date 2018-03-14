#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() 
{
    ios::sync_with_stdio(false);
    
    int N, M, K;
    cin >> N >> M >> K;
    int res = 0;
    for (int x1 = 0; x1 <= N; ++x1) {
        for (int y1 = 0; y1 <= M; ++y1) {
            for (int x2 = 0; x2 <= N; ++x2) {
                for (int y2 = 0; y2 <= M; ++y2) {
                    if (gcd(abs(x1 - x2), abs(y1 - y2)) + 1 == K) {
                        ++res;
                    }
                }
            }
        }
    }
    cout << res / 2 << endl;
    
    return 0;
}