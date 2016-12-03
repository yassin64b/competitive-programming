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

    sort(a.begin(), a.end());
    int64_t moves = 0;
    for (int i = 0; i < n; ++i) {
        moves += abs((int64_t)a[i] - (i + 1));
    }
    cout << moves << endl;

    return 0;
}