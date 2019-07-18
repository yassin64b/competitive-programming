#include <bits/stdc++.h>

using namespace std;

vector<int> get_sums(vector<int> t, int x) {
    int m = t.size();
    vector<int> sums;
    for (int i = 1; i < (1 << m); ++i) {
        int sum = 0;
        for (int j = 0; j < m && sum <= x; ++j) {
            if (i & (1 << j)) {
                sum += t[j];
            }
        }
        if (sum <= x) sums.push_back(sum);
    }
    return sums;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }
    int m = (n + 1) / 2;
    vector<int> sums1(get_sums(vector<int>(begin(t), begin(t) + m), x));
    vector<int> sums2(get_sums(vector<int>(begin(t) + m, end(t)), x));
    sort(begin(sums1), end(sums1));
    sort(begin(sums2), end(sums2));

    long long res = 0;
    for (int y : sums1) {
        res += (y == x);
    }
    for (int y : sums2) {
        res += (y == x);
    }

    int n1 = sums1.size(), n2 = sums2.size();
    for (int i = 0, j = n2 - 1; i < n1; ++i) {
        int ie = i;
        while (ie < n1 && sums1[ie] == sums1[i]) ++ie;
        int cnt1 = ie - i;

        while (j >= 0 && sums2[j] + sums1[i] > x) --j;
        if (j == -1 || sums2[j] + sums1[i] < x) continue;
        int je = j;
        while (je >= 0 && sums2[je] == sums2[j]) --je;
        int cnt2 = j - je;

        res += 1LL * cnt1 * cnt2;

        i = ie - 1;
        j = je;
    }
    cout << res << "\n";

    return 0;
}