#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, t;
    cin >> n >> t;
    int ind = -1, dist = 1'000'000'000;
    for (int i = 0; i < n; ++i) {
        int s, d;
        cin >> s >> d;
        int cur_dist;
        if (t < s) {
            cur_dist = s - t;
        } else {
            cur_dist = (d - ((t - s) % d)) % d;
        }
        if (cur_dist < dist) {
            dist = cur_dist;
            ind = i + 1;
        }
    }
    cout << ind << "\n";
    return 0;
}