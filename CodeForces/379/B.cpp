#include <iostream>
#include <cstdlib>
using namespace std;
int main() {
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;

    int num256 = min(k2, min(k5, k6));
    k2 -= num256;
    k2 = max(k2, 0);
    int num32 = min(k2, k3);
    cout << num32 * 32 + num256 * 256 << endl;

    return 0;
}