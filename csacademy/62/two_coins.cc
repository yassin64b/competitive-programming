#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    set<int> res;
    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i)
        cin >> v[i];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i != j)
                res.insert(v[i] + v[j]);
        }
    }
    cout << res.size() << "\n";
    
    return 0;
}