#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<pair<int, int>> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i].first >> v[i].second;
    }
    multiset<pair<int, pair<int, int>>> a, b;
    for (int i = 0; i < N; ++i) {
        a.insert({-(v[i].first + v[i].second), {-v[i].first, v[i].second}});
        b.insert({-(v[i].second + v[i].first), {-v[i].second, v[i].first}});
    }
    long long res = 0;
    for (int i = 0; i < N; ++i) {
        if (i % 2 == 0) {
            const auto &p = *a.begin();
            int v1 = -p.second.first, v2 = p.second.second;
            res += v1;
            a.erase(a.begin());
            b.erase(b.find({- v2 - v1, {-v2, v1}}));
        } else {
            const auto &p = *b.begin();
            int v1 = p.second.second, v2 = -p.second.first;
            res -= v2;
            b.erase(b.begin());
            a.erase(a.find({- v1 - v2, {-v1, v2}}));
        }
    }
    cout << res << "\n";
    return 0;
}