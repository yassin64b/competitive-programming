#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> V(N);
    for (int i = 0; i < N; ++i)
        cin >> V[i];
    for (int i = 0; i < N; ++i)
        V[i] -= i;
    
    multiset<int> lis;
    for (int i = 0; i < N; ++i) {
        if (lis.upper_bound(V[i]) == lis.end())
            lis.insert(V[i]);
        else {
            lis.erase(lis.upper_bound(V[i]));
            lis.insert(V[i]);
        }
    }
    cout << N - lis.size() << "\n";
    
    return 0;
}