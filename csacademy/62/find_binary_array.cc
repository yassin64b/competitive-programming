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
    vector<int> left(N), right(N);
    for (int i = 0; i < N; ++i) 
        cin >> left[i];
    for (int i = 0; i < N; ++i)
        cin >> right[i];
    vector<int> res(N, 0);
    int cur = 0;
    for (int i = 0; i + 1 < N; ++i) 
        if (left[i + 1] > cur)
            res[i] = 0, ++cur;
        else
            res[i] = 1;
    if (right[N - 2] == 0)
        res[N - 1] = 1;
        
    for (int x : res)
        cout << x;
    cout << "\n";
    
    return 0;
}