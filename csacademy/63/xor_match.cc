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
    vector<int> A(N), B(M);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < M; ++i)
        cin >> B[i];
    int res = 0;
    for (int j = 0; j <= M - N; ++j) {
        bool ok = true;
        for (int i = 0; i < N; ++i)
            if (A[i] + B[i + j] != 1)
                ok = false;
        res += ok;
    }
    cout << res << "\n";
    
    return 0;
}