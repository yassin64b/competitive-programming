#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<int> cur_in, day_in;
    vector<int> c;
    int cur_cnt = 0;
    bool ok = true;
    for (int i = 0; ok && i < n; ++i) {
        ++cur_cnt;
        if (a[i] > 0) {
            if (cur_in.count(a[i]) || day_in.count(a[i])) {
                ok = false;
                break;
            }
            cur_in.insert(a[i]);
            day_in.insert(a[i]);
        } else {
            a[i] *= -1;
            if (!cur_in.count(a[i])) {
                ok = false;
                break;
            }
            cur_in.erase(a[i]);
        }
        if (cur_in.empty()) {
            c.push_back(cur_cnt);
            cur_cnt = 0;
            day_in.clear();
        }
    }
    if (!cur_in.empty()) {
        ok = false;
    }
    if (ok) {
        cout << c.size() << "\n";
        for (int x : c) {
            cout << x << " ";
        }
        cout << "\n";
    } else {
        cout << -1 << "\n";
    }

    return 0;
}