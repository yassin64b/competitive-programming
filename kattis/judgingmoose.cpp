#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int l, r;
    cin >> l >> r;
    if (!l && !r) {
        cout << "Not a moose\n";
        return 0;
    }
    if (l == r) {
        cout << "Even ";
    } else {
        cout << "Odd ";
    }
    cout << max(l, r) * 2 << "\n";
}