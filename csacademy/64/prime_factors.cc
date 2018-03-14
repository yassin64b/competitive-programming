#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    vector<int> primes{2, 3, 5, 7};
    int res = 1;
    for (int p : primes) {
        cout << "Q " << p << "\n";
        cout.flush();
        int x;
        cin >> x;
        for (int i = 0; i < x; ++i)
            res *= p;
    }
    cout << "A " << res << "\n";
    
    return 0;
}