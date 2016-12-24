#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    int q;
    cin >> q;

    vector<int> m(q);
    for (int i = 0; i < q; ++i) {
        cin >> m[i];
    }

    sort(x.begin(), x.end());

    for (int i = 0; i < q; ++i) {
        int l = 0, r = n-1;
        while (l < r) {
            int mid = (l + r) / 2;
            if (x[mid] < m[i]) {
                l = mid + 1;
            } else if (x[mid] > m[i]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (x[r] > m[i]) cout << r << endl;
        else cout << r+1 << endl;
    }
    return 0;
}