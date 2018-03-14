#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    long long mx = 0, sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += A[i];
        if (i % 2 == 1) {
            mx = max(mx, sum);
        }
    }
    cout << mx << endl;
    
    return 0;
}