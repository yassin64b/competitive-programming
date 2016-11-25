#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    int len = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 < len || len == 0) {
            len = r - l + 1;
        }
    }
    cout << len << endl;
    for (int i = 0; i < n; ++i) {
        cout << i % len << " ";
    }

    return 0;
}