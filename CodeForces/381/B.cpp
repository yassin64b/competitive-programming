#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int res = 0;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        int sum = 0;
        for (; l <= r; ++l) {
            sum += a[l-1];
        }
        res += max(sum, 0);
    }
    cout << res << endl;
    return 0;
}