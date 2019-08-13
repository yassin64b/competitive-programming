#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    vector<int> D(K), forb(10, 0);
    for (int i = 0; i < K; ++i) {
        cin >> D[i];
        forb[D[i]] = 1;
    }
    int smallest_ok = 9, smallest_larg1 = 9;
    for (int i = 9; i >= 0; --i) {
        if (!forb[i]) {
            smallest_ok = i;
            if (i > 0) smallest_larg1 = i;
        }
    }
    string s(to_string(N));
    bool larger = false;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (forb[s[i] - '0'] || larger) {
            if (larger) {
                s[i] = smallest_ok + '0';
            } else {
                bool success = false;
                for (int k = i; !success && k >= 0; --k) {
                    for (int j = s[i] - '0' + 1; !success && j <= 9; ++j) {
                        if (!forb[j]) {
                            s[k] = j + '0';
                            success = true;
                        }
                    }
                }
                if (!success) {
                    string tmp;
                    tmp += (smallest_larg1 + '0');
                    tmp += s;
                    s = tmp;
                    i = 0;
                }
                larger = true;
            }
        }
    }
    cout << s << "\n";

    return 0;
}