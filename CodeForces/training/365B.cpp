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

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n <= 2) {
        cout << n << endl;
        return 0;
    }

    int mxlen = 2, len = 2;
    for (int i = 2; i < n; ++i) {
        if (a[i] == a[i-1] + a[i-2]) {
            ++len;
            mxlen = max(mxlen, len);
        } else {
            len = 2;
        }
    }

    cout << mxlen << endl;

    return 0;
}