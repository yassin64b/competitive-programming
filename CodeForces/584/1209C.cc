#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        string d;
        cin >> d;
        bool found = false;
        for (int upto = 0; upto <= 9; ++upto) {
            string s1, s2;
            string t;
            int largest_2 = -1;
            for (int i = 0; i < n; ++i) {
                if (d[i] - '0' <= upto || d[i] - '0' < largest_2) {
                    s1 += d[i];
                    t += '1';
                } else {
                    largest_2 = max(largest_2, d[i] - '0');
                    s2 += d[i];
                    t += '2';
                }
            }
            bool ok = true;
            for (int i = 0; i + 1 < (int)s1.size(); ++i) {
                if (s1[i] > s1[i + 1]) {
                    ok = false;
                }
            }
            for (int i = 0; i + 1 < (int)s2.size(); ++i) {
                if (s2[i] > s2[i + 1]) {
                    ok = false;
                }
            }
            if (!s1.empty() && !s2.empty() && s1.back() > s2[0]) {
                ok = false;
            }
            if (ok) {
                found = true;
                cout << t << "\n";
                break;
            }
        }
        if (!found) {
            cout << "-" << "\n";
        }
    }
    return 0;
}