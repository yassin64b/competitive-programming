#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int A, B;
    cin >> A >> B;
    int val = -1, mx = -1;
    for ( ; A <= B; ++A) {
        int j = A, res = 0;
        do {
            int d = j % 10;
            res += 1 * (d == 0 || d == 6 || d == 9) + 2 * (d == 8);
            j /= 10;
        } while (j);
        if (res > mx) {
            mx = res;
            val = A;
        }
    }
    cout << val << endl;
    
    return 0;
}