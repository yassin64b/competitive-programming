#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<i64> res(n, n);
    
    deque<i64> mn, mx;
    map<i64, i64> t;
    for (int i = 0; i < n; ++i) {
        i64 need1 = a[i] + k, need2 = a[i] - k;
        if (!mx.empty() && mx.front() >= need1) {
            int low = 0, high = (int)mx.size() - 1, ans = low;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mx[mid] >= need1) {
                    low = mid + 1;
                    ans = mid;
                } else {
                    high = mid - 1;
                }
            }
            res[i] = min(res[i], i - t[mx[ans]]);
        }
        if (!mn.empty() && mn.front() <= need2) {
            int low = 0, high = (int)mn.size() - 1, ans = low;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mn[mid] <= need2) {
                    low = mid + 1;
                    ans = mid;
                } else {
                    high = mid - 1;
                }
            }
            res[i] = min(res[i], i - t[mn[ans]]);
        }
        
        t[a[i]] = i;
        while (!mx.empty() && mx.back() < a[i]) {
            mx.pop_back();
        }
        mx.push_back(a[i]);

        while (!mn.empty() && mn.back() > a[i]) {
            mn.pop_back();
        }
        mn.push_back(a[i]);
    }

    mn.clear();
    mx.clear();
    t.clear();
    for (int i = n - 1; i >= 0; --i) {
        i64 need1 = a[i] + k, need2 = a[i] - k;
        if (!mx.empty() && mx.front() >= need1) {
            int low = 0, high = (int)mx.size() - 1, ans = low;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mx[mid] >= need1) {
                    low = mid + 1;
                    ans = mid;
                } else {
                    high = mid - 1;
                }
            }
            res[i] = min(res[i], t[mx[ans]] - i);
        }
        if (!mn.empty() && mn.front() <= need2) {
            int low = 0, high = (int)mn.size() - 1, ans = low;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (mn[mid] <= need2) {
                    low = mid + 1;
                    ans = mid;
                } else {
                    high = mid - 1;
                }
            }
            res[i] = min(res[i], t[mn[ans]] - i);
        }
        
        t[a[i]] = i;
        while (!mx.empty() && mx.back() < a[i]) {
            mx.pop_back();
        }
        mx.push_back(a[i]);

        while (!mn.empty() && mn.back() > a[i]) {
            mn.pop_back();
        }
        mn.push_back(a[i]);
    }

    cout << accumulate(begin(res), end(res), 0LL) << "\n";

    return 0;
}