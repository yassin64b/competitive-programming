#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;


int main() 
{
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for(int i = 0; i < N; ++i)
        cin >> A[i];

    vector<int> maxA(N);
    maxA[N-1] = A[N-1];
    for(int i = N-2; i >= 0; --i)
        maxA[i] = max(maxA[i+1], A[i]);

    vector<int> inds{0};
    for(int i = 1; i < N; ++i)
    {
        if(maxA[i] - A[i] > maxA[inds[0]] - A[inds[0]])
            inds.clear(), inds.push_back(i);
        else if(maxA[i] - A[i] == maxA[inds[0]] - A[inds[0]])
            inds.push_back(i);
    }
    cout << inds.size() << endl;

    return 0;
}