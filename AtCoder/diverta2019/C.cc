#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<string> s(N);
    vector<string> ab, b, a, x;
    for (int i = 0; i < N; ++i) {
        cin >> s[i];
        for (char &c : s[i]) {
            c = tolower(c);
        }
        if (s[i][0] == 'b' && s[i].back() == 'a') {
            ab.push_back(s[i]);
        } else if (s[i][0] == 'b') {
            b.push_back(s[i]);
        } else if (s[i].back() == 'a') {
            a.push_back(s[i]);
        } else {
            x.push_back(s[i]);
        }
    }

    string res;
    if (!a.empty()) {
        res += a[0];
    }
    for (const string &t : ab) {
        res += t;
    }
    int i, j;
    for (i = 0, j = 1; i < (int)b.size() && j < (int)a.size(); ++i, ++j) {
        res += b[i];
        res += a[j];
    }
    for (; i < (int)b.size(); ++i) {
        res += b[i];
    }
    for (; j < (int)a.size(); ++j) {
        res += a[j];
    }
    for (const string &t : x) {
        res += t;
    }
    int cnt = 0;
    for (int i = 0; i + 1 < (int)res.size(); ++i) {
        cnt += res[i] == 'a' && res[i + 1] == 'b';
    }
    cout << cnt << "\n";

    return 0;
}