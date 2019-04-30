#include <bits/stdc++.h>

using namespace std;

string solve(vector<int> &a, int last) {
    int n = a.size();
    string res;
    for (int i = 0, j = n - 1; i <= j; ) {
        bool left = (a[i] > last), right = (a[j] > last);
        if (left && right) {
            if (a[i] < a[j]) {
                res += 'L';
                last = a[i];
                ++i;
            } else {
                res += 'R';
                last = a[j];
                --j;
            }
        } else if (left) {
            res += 'L';
            last = a[i];
            ++i;
        } else if (right) {
            res += 'R';
            last = a[j];
            --j;
        } else {
            break;
        }
    }
    return res;
}
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }   
    string res;
    for (int i = 0, j = n - 1, last = 0; i <= j; ) {
        bool left = (a[i] > last), right = (a[j] > last);
        if (left && right) {
            if (a[i] < a[j]) {
                res += 'L';
                last = a[i];
                ++i;
            } else if (a[i] > a[j]) {
                res += 'R';
                last = a[j];
                --j;
            } else {
                int len = j - i;
                vector<int> b1(begin(a) + i, begin(a) + i + len);
                vector<int> b2(begin(a) + i + 1, begin(a) + i + 1 + len);
                string res1 = solve(b1, a[i]);
                string res2 = solve(b2, a[i]);
                if (res1.size() > res2.size()) {
                    res += 'R';
                    res += res1;
                } else {
                    res += 'L';
                    res += res2;
                }
                break;
            }
        } else if (left) {
            res += 'L';
            last = a[i];
            ++i;
        } else if (right) {
            res += 'R';
            last = a[j];
            --j;
        } else {
            break;
        }
    }
    cout << res.size() << "\n" << res << "\n";

    return 0;
}