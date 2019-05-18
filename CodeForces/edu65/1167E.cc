#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    vector<vector<int>> inv(x + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        inv[a[i]].push_back(i);
    }
    int low = 1, high = x, ans = high;
    while (low <= high) {
        int mid = (low + high) / 2;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            if (a[i] > mid) {
                v.push_back(a[i]);
            }
        }
        bool ok = true;
        for (int i = 0; ok && i + 1 < (int)v.size(); ++i) {
            if (v[i] > v[i + 1]) {
                ok = false;
            }
        }
        if (ok) {
            high = mid - 1;
            ans = mid;
        } else {
            low = mid + 1;
        }
    }
    set<int> cur;
    for (int i = 0; i < n; ++i) {
        if (a[i] > ans) {
            cur.emplace(i);
        }
    }
    long long res = 0;
    for (int l = 1, r = ans; l <= x; ++l) {
        //cout << l << " " << r << endl;
        res += (x - min(x, r) + 1);

        r = max(r, l + 1);
        // readd elements with value l
        for (int i : inv[l]) {
            auto it = cur.upper_bound(i);
            while (it != begin(cur)) {
                --it;
                if (a[*it] > l) { // erase elements before i with larger val
                    for (; r <= a[*it]; ++r) { // by advancing r
                        for (int j : inv[r]) {
                            if (j != *it) { // watch out for iterator invalidation
                                cur.erase(j);
                            }
                        }
                    }
                    --r;
                    it = cur.erase(it); // delete this at the end (it invalidation)
                } else {
                    break;
                }
            }
            it = cur.upper_bound(i);
            if (it != end(cur) && a[*it] < l) {
                goto end;
            }
            cur.insert(i);
        }
    }
    end:
    cout << res << "\n";

    return 0;
}