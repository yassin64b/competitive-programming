#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    unordered_set<string> seen;
    string s;
    while (cin >> s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            string tmp = s.substr(0, i) + s.substr(i + 1);
            if (seen.count(tmp)) {
                cout << tmp << endl;
                return 0;
            }
        }
        for (int i = 0; i < n; ++i) {
            string tmp = s.substr(0, i) + s.substr(i + 1);
            seen.insert(tmp);
        }
           
    }
    
    return 0;
}
