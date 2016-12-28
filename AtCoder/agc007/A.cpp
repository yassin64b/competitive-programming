#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


int main() 
{
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<char>> A(H, vector<char>(W));
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> A[i][j];

    vector<int> right(H, 0), left(H, 0);
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == '#') {
                left[i] = j;
                break;
            }
        }
        for (int j = 0; j < W; ++j) {
            if (A[i][j] == '#') right[i] = j;
        }
    }

    for (int i = 0; i < H-1; ++i) {
        if (right[i] > left[i+1]) {
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}