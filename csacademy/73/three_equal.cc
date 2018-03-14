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
    int c0 = 0, c1 = 0, c2 = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            c1 += 1;
            c2 += 2;
        } else if (a == 1) {
            c2 += 1;
            c0 += 2;
        } else {
            c0 += 1;
            c1 += 2;
        }
    }
    cout << min(c0, min(c1, c2)) << endl;
    
    return 0;
}