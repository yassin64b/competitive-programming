#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> A[i][j];
        }
    }
    vector<vector<int>> down(N, vector<int>(M, 0));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = i; k < N && A[k][j]; ++k) {
                ++down[i][j];
            }
        }
    }
    int res = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            for (int k = j; k < M && A[i][k]; ++k) {
                if (k > j && down[i][k] > 1) {
                    res = max(res, k - j + down[i][k]);
                }
            }
        }
    }
    cout << res << endl;
    
    return 0;
}