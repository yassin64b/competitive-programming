#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
    
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    if (n % 4 == 0) {
    	cout << 0 << endl;
    } else if (n % 4 == 1) {
    	long long res = min(3 * a, min(a + b, c));
    	cout << res << endl;
    } else if (n % 4 == 2) {
    	long long res = min(2 * a, min(b, 2 * c));
    	cout << res << endl;
    } else if (n % 4 == 3) {
    	long long res = min(a, min(b + c, 3 * c));
    	cout << res << endl;
    }
    return 0;
}