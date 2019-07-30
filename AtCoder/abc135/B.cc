#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }
    bool swapped = false;
    for (int i = 0; !swapped && i < N; ++i) {
        for (int j = i + 1; !swapped && j < N; ++j) {
            if (p[i] == j + 1 && p[j] == i + 1) {
                swap(p[j], p[i]);
                swapped = true;
            }
        }
    }
    if (is_sorted(begin(p), end(p))) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}