#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<string, int> m;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        sort(begin(s), end(s));
        ++m[s];
    }
    long long res = 0;
    for (const auto p : m) {
        res += 1LL * p.second * (p.second - 1) / 2;
    }
    cout << res << "\n";

    return 0;
}