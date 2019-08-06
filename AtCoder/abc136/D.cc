#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();
    vector<int> res(n, 0);
    for (int i = 0, j = 0; i < n; ++i) {
        if (S[i] == 'R') {
            j = max(i, j);
            while (j < n && S[j] == 'R') {
                ++j;
            }
            assert(j < n);
            int dist = j - i;
            if (dist % 2 == 1) {
                ++res[j - 1];
            } else {
                ++res[j];
            }
        }
    }
    for (int i = n - 1, j = n - 1; i >= 0; --i) {
        if (S[i] == 'L') {
            j = min(i, j);
            while (j >= 0 && S[j] == 'L') {
                --j;
            }
            assert(j >= 0);
            int dist = i - j;
            if (dist % 2 == 1) {
                ++res[j + 1];
            } else {
                ++res[j];
            }
        }
    }
    for (int x : res) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}