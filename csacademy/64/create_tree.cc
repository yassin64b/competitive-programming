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
    
    for (int i = 2; i <= N; ++i) {
        int tmp = 0;
        do {
            cout << "Q " << 1 << " " << i << "\n";
            cout.flush();
            cin >> tmp;
        } while (tmp == 0);
    }
    
    cout << "A" << "\n";
    cout.flush();
    
    return 0;
}