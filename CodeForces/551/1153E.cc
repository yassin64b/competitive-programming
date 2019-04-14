#include <bits/stdc++.h>

using namespace std;

int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int ans;
    cin >> ans;
    if (ans == -1) {
        exit(0);
    }
    return ans % 2;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> odd_rows;
    for (int x = 1; x <= n - 1; ++x) {
        if (query(x, 1, x, n)) {
            odd_rows.push_back(x);
        }
    }
    vector<int> res;
    if (odd_rows.empty()) {
        vector<int> odd_cols;
        for (int y = 1; y <= n - 1; ++y) {
            if (query(1, y, n, y)) {
                odd_cols.push_back(y);
            }
        }
        assert(!odd_cols.empty());
        if (odd_cols.size() == 1U) {
            odd_cols.push_back(n);
        }
        assert(odd_cols.size() == 2U);
        for (int y : odd_cols) {
            int low = 1, high = n, x = low;
            while (low < high) {
                int mid = (low + high) / 2;
                if (query(low, y, mid, y)) {
                    x = low;
                    high = mid;
                } else {
                    low = mid + 1;
                    x = low;
                }
            }
            res.push_back(x);
            res.push_back(y);
        }
    } else {
        if (odd_rows.size() == 1U) {
            odd_rows.push_back(n);
        }
        assert(odd_rows.size() == 2U);
        for (int x : odd_rows) {
            int low = 1, high = n, y = low;
            while (low < high) {
                int mid = (low + high) / 2;
                if (query(x, low, x, mid)) {
                    y = low;
                    high = mid;
                } else {
                    low = mid + 1;
                    y = low;
                }
            }
            res.push_back(x);
            res.push_back(y);
        }
    }
    cout << "! ";
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}