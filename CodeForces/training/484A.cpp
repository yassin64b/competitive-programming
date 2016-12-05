#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

/*uint64_t f(uint64_t l, uint64_t r) 
{
    if (l == r) {
        return l;
    }
    uint64_t x = 1;
    while (x <= r) {
        x <<= 1;
    }
    x >>= 1;
    if (x <= l) {
        return f(l - x, r - x) + x;
    }

    x <<= 1;
    x -= 1;
    if (x <= r) {
        return x;
    }

    return ((x + 1) >> 1) - 1;
}*/

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        uint64_t l, r;
        cin >> l >> r;

        if (l == r) {
            cout << l << endl;
            continue;
        }
        uint64_t x = l;
        while ((x | (x + 1)) <= r) {
            x = x | (x + 1);
        }
        cout << x << endl;
        //cout << f(l, r) << endl;
    }
    

    return 0;
}