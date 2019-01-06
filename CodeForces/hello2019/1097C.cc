#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
    }

    constexpr int MX = 500'001;
    vector<int> bal(2 * MX + 1);
    for (int i = 0; i < n; ++i) {
        const int m = seq[i].size();
        int cur_open = 0, cur_closed = 0;
        for (int j = 0; j < m; ++j) {
            if (seq[i][j] == '(') {
                ++cur_open;
            } else {
                cur_open = max(0, cur_open - 1);
            }
        }
        for (int j = m - 1; j >= 0; --j) {
            if (seq[i][j] == '(') {
                cur_closed = max(0, cur_closed - 1);
            } else {
                ++cur_closed;
            }
        }
        if (cur_open == 0) {
            bal[cur_closed + MX]++;
        } else if (cur_closed == 0) {
            bal[-cur_open + MX]++;
        }
        //cout << seq[i] << ": " << cur_open << " " << cur_closed << endl;
    }

    int res = bal[0 + MX] / 2;
    for (int cur_bal = 1; cur_bal < MX; ++cur_bal) {
        int i = cur_bal + MX;
        int j = -cur_bal + MX;
        res += min(bal[i], bal[j]);
    }
    cout << res << "\n";
    
    return 0;
}