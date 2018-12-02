#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    int cnt2 = 0, cnt3 = 0;
    string s;
    while (cin >> s) {
        map<char, int> cnt;
        for (char c : s) {
            ++cnt[c];
        }
        bool b2 = false, b3 = false;
        for (auto [k, v] : cnt) {
            if (v == 2) {
                b2 = true;
            } else if (v == 3) {
                b3 = true;
            }
        }
        cnt2 += b2;
        cnt3 += b3;
    }
    cout << cnt2 * cnt3 << endl;
    
    return 0;
}
