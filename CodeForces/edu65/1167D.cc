#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> res(n, 0);
    constexpr int r = 0, g = 1;
    int cur_r = 0, cur_g = 0;
    for (int i = 0; i < n; ++i) {
        if (cur_r <= cur_g) {
            if (s[i] == '(') {
                res[i] = r;
                ++cur_r;
            } else {
                res[i] = g;
                --cur_g;
            }
        } else {
            if (s[i] == '(') {
                res[i] = g;
                ++cur_g;
            } else {
                res[i] = r;
                --cur_r;
            }
        }
    }
    for (int x : res) {
        cout << x;
    }
    cout << "\n";

    return 0;
}