#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int x;
    cin >> x;
    int num_op = 0;
    vector<int> res;
    for (int i = 0; i < 20; ++i) {
        int y = x + 1;
        int hi = 0;
        for (int j = 0; j <= 20; ++j) {
            if (y & (1 << j)) hi = j;
        }
        int low = 0;
        for (int j = 20; j >= 0; --j) {
            if (y & (1 << j)) low = j;
        }
        if (hi == low) {
            break;
        }

        low = 0;
        for (int j = 20; j >= 0; --j) {
            if (x & (1 << j)) low = j;
        }
        res.push_back(low);
        x ^= (1 << low) - 1;
        ++num_op;

        y = x + 1;
        hi = 0;
        for (int j = 0; j <= 20; ++j) {
            if (y & (1 << j)) hi = j;
        }
        low = 0;
        for (int j = 20; j >= 0; --j) {
            if (y & (1 << j)) low = j;
        }
        if (hi == low) {
            break;
        }

        ++num_op;
        x = x + 1;
    }
    cout << num_op << "\n";
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}