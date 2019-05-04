#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> p(n), inv(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
        inv[p[i]] = i;
    }
    vector<int> l(n, 0), r(n, n - 1);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        while (!s.empty() && p[s.top()] < p[i]) {
            s.pop();
        }
        if (!s.empty()) {
            l[i] = s.top() + 1;
        }
        s.push(i);
    }
    s = stack<int>();
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && p[s.top()] < p[i]) {
            s.pop();
        }
        if (!s.empty()) {
            r[i] = s.top() - 1;
        }
        s.push(i);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        int left_sz = i - l[i], right_sz = r[i] - i;
        if (left_sz < right_sz) {
            for (int j = l[i]; j < i; ++j) {
                int need = p[i] + 1 - (p[j] + 1) - 1;
                int ind = inv[need];
                if (ind > i && ind <= r[i]) {
                    ++res;
                }
            }
        } else {
            for (int j = i + 1; j <= r[i]; ++j) {
                int need = p[i] + 1 - (p[j] + 1) - 1;
                int ind = inv[need];
                if (ind >= l[i] && ind < i) {
                    ++res;
                }
            }
        }
    }
    cout << res << "\n";


    return 0;
}