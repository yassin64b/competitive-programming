#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n, k, a, b;
    cin >> n >> k >> a >> b;

    int mn = min(a, b), mx = max(a, b);

    /*if ((mn+1) * (int64_t)k < mx) {
        cout << "NO" << endl;
        return 0;
    }*/

    vector<int> res(n);
    int cur = 0;
    for (int i = 0; i < n; ++i) {
        if (mx > mn && cur < k) {
            ++cur;
            res[i] = 1;
            --mx;
        } else {
            cur = 0;
            res[i] = 0;
            --mn;
        }
    }

    if (mn < 0 || mx < 0) {
        cout << "NO" << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (a > b) {
            if (res[i] == 1) {
                cout << 'G';
            } else {
                cout << 'B';
            }
        } else {
            if (res[i] == 1) {
                cout << 'B';
            } else {
                cout << 'G';
            }
        }
    }


    return 0;
}