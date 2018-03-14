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
    vector<string> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < N; ++i) {
        bool ok = false;
        for (int j = 0; !ok && j < N; ++j) {
            for (int k = 0; !ok && k < N; ++k) {
                if (j != i && k != i && j != k && v[i] == v[j] + v[k]) {
                    ok = true;
                }
            }
        }
        if (ok) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;
    
    return 0;
}