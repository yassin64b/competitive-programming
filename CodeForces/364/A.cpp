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

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    sum /= n / 2;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -1) continue;
        for (int j = i+1; j < n; ++j) {
            if (a[j] == -1) continue;
            if (a[i] + a[j] == sum) {
                cout << i+1 << " " << j+1 << endl;
                a[i] = a[j] = -1;
            }
        }
    }

    return 0;
}