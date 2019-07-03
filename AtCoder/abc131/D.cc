#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> BA(N);
    for (int i = 0; i < N; ++i) {
        cin >> BA[i].second >> BA[i].first;
    }
    sort(begin(BA), end(BA));
    int t = 0;
    for (int i = 0; i < N; ++i) {
        t += BA[i].second;
        if (t > BA[i].first) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    
    return 0;
}