#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int64_t n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;

    int64_t numGroups = (n + k - 1) / k;

    double low = 0, high = (double)l / v1, mid;
    double time;
    while (high - low >= 5e-9) {
        mid = (low + high) / 2.;
        time = 0;

        for (int i = 0; i < numGroups; ++i) {
            double x = (l - v1 * mid) / (v2 - v1);
            time += x;

            if (i+1 < numGroups) {
                double y = x * (v2 - v1) / (v2 + v1);
                time += y;
            }
        }

        if (time > mid) {
            low = mid;
        } else {
            high = mid;
        }
    }
    cout.precision(17);
    cout << fixed << low << endl;


    return 0;
}