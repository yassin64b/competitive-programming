#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<string> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    unordered_map<string, vector<string>> res;

    for (int i = 0; i < n; ++i) {
        string s;
        vector<int> key(k);
        for (int j = 0; j < k; ++j) {
            key[j] = (26 - (w[i][j] - 'A'));
        }
        for (int j = 0; j < (int)w[i].size(); ++j) {
            s += ((w[i][j] - 'A') + key[j % k]) % 26 + 'A';
        }
        res[s].push_back(w[i]);
    }

    for (const auto &p : res) {
        for (const string &s : p.second) {
            cout << s << " ";
        }
        cout << "\n";
    }

    return 0;
}