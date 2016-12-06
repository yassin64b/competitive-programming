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

    unsigned int n, x;
    cin >> n >> x;

    vector<unsigned int> a(n);
    map<unsigned int, int> m;
    for (size_t i = 0; i < n; ++i) {
        cin >> a[i];
        m[a[i]]++;
    }

    int64_t cnt = 0;
    for (size_t i = 0; i < n; ++i) {
        unsigned int b = a[i] ^ x;
        //cout << a[i] << " " << b << endl;
        if (a[i] != b && m[b] >= 1) {
            cnt += m[b];
        } else if (m[b] >= 2) {
            cnt += m[b] - 1;
        }
    }

    cout << cnt/2 << endl;

    return 0;
}