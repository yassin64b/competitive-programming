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

    vector<string> puzzle(n);
    for (int i = 0; i < n; ++i) {
        cin >> puzzle[i];
    }

    set<int> row, col;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (puzzle[i][j] == 'X') {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for (const int &r : row) {
        for (const int &c : col) {
            if (puzzle[r][c] != 'X') {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;

    return 0;
}