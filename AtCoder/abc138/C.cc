#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }
    sort(begin(v), end(v));
    double res = v[0];
    for (int i = 1; i < N; ++i) {
        res = (res + v[i]) / 2;
    }
    cout.precision(17);
    cout << fixed << res << "\n";

    return 0;
}