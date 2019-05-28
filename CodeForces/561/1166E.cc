#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> v(m);
    for (int i = 0; i < m; ++i) {
        int s;
        cin >> s;
        v[i].resize(s);
        for (int j = 0; j < s; ++j) {
            cin >> v[i][j];
        }
        sort(begin(v[i]), end(v[i]));
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            vector<int> intersec;
            set_intersection(begin(v[i]), end(v[i]),
                            begin(v[j]), end(v[j]), 
                            back_inserter(intersec));
            if (intersec.empty()) {
                cout << "impossible\n";
                return 0;
            }
        }
    }
    cout << "possible\n";
    return 0;
}