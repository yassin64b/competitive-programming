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

    int n, m;
    cin >> n >> m;

    set<int> col, row;
    for (int i = 0; i < n; ++i) {
        col.insert(i+1);
        row.insert(i+1);
    }
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        row.erase(x);
        col.erase(y);
        cout << row.size() * (uint64_t)col.size() << " ";
    }
    cout << endl;

    return 0;
}