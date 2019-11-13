#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    vector<pair<int, int>> ba(N);
    for (int i = 0; i < N; ++i) {
        ba[i] = {B[i], A[i]};
    }
    sort(begin(ba), end(ba));
    sort(begin(A), end(A));
    map<int, int> pos;
    for (int i = 0; i < N; ++i) {
        pos[ba[i].second] = i;
        if (A[i] > ba[i].first) {
            cout << "No\n";
            return 0;
        }
    }
    for (int i = 0; i + 1 < N; ++i) {
        if (A[i + 1] <= ba[i].first) {
            cout << "Yes\n";
            return 0;
        }
    }
    vector<int> vis(N, 0);
    int i = A[0];
    while (!vis[i]) {
        vis[i] = 1;
        int need = pos[A[i]];
        i = need;
    }
    if (count(begin(vis), end(vis), 0) == 0) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}