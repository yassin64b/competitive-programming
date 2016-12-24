#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int64_t n, k;
    cin >> n >> k;

    int64_t len = pow(2, n);
    int64_t l = 1, r = len;
    int mx = n;
    while (true) {
        int64_t mid = (l + r) / 2;
        if (k < mid) {
            r = mid - 1;
            --mx;
        } else if (k > mid) {
            l = mid + 1;
            --mx;
        } else {
            cout << mx << endl;
            return 0;
        }
    }

    cout << 0 << endl;
    return 0;
}