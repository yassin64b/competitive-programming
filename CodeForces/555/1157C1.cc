#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    string res;
    for (int i = 0, j = n - 1, last = 0; i <= j; ) {
        bool left = (a[i] > last), right = (a[j] > last);
        if (left && right) {
            if (a[i] < a[j]) {
                res += 'L';
                last = a[i];
                ++i;
            } else {
                res += 'R';
                last = a[j];
                --j;
            }
        } else if (left) {
            res += 'L';
            last = a[i];
            ++i;
        } else if (right) {
            res += 'R';
            last = a[j];
            --j;
        } else {
            break;
        }
    }
    cout << res.size() << "\n" << res << "\n";

    return 0;
}