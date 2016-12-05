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

    int n;
    cin >> n;
    vector<int> b(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());

    int last = 0;
    for (int i = 0; i < n; ++i) {
        if (last >= a[i].first) {
            b[a[i].second] = ++last;
        } else {
            b[a[i].second] = last = a[i].first;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << b[i] << " ";
    }

    return 0;
}