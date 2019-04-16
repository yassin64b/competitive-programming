#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, b, a;
    cin >> n >> b >> a;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }   
    int cur_a = a, res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 0) {
            if (cur_a) {
                --cur_a;
            } else {
                if (!b) {
                    break;
                }
                --b;
            }
        } else {
            if (b && cur_a < a) {
                --b;
                ++cur_a;
            } else {
                if (!cur_a) {
                    break;
                }
                --cur_a;
            }
        }
        res = i + 1;
    }
    cout << res << "\n";
    
    return 0;
}