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
    vector<int> res(N, 0);
    int ind = 0;
    for (int i = 1; i < N; ++i) {
        if (A[i] > A[ind]) {
            ind = i;
        }
        ++res[ind];
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
    
    return 0;
}