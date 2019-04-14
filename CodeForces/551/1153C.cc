#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    int bal = 0;
    for (int i = 0; i < n; ++i) {
        bal -= (s[i] == '(');
        bal += (s[i] == ')');
    }
    int cnt = count(begin(s), end(s), '?');
    int cntopen = 0;
    if (bal > 0) {
        cntopen += bal;
        cnt -= bal;
    } else {
        cnt += bal;
    }
    cntopen += cnt / 2;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?') {
            if (cntopen) {
                s[i] = '(';
                --cntopen;
            } else {
                s[i] = ')';
            }
        }
    }
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            ++cnt;
        } else {
            --cnt;
        }
        if ((i < n - 1 && cnt == 0) || cnt < 0) {
            cout << ":(\n";
            return 0;
        }
    }
    if (cnt != 0) {
        cout << ":(\n";
        return 0;
    }

    cout << s << endl;

    return 0;
}