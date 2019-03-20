#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    set<int> a;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int cur;
        cin >> cur;
        sum += cur;
        a.insert(cur);
    }
    int best = sum;
    constexpr int MX = 100;
    for (int v1 : a) {
        for (int x = 2; x <= MX; ++x) {
            if (v1 % x) continue;
            for (int v2 : a) {
                int cur_sum = sum;
                cur_sum += v1 / x - v1;
                cur_sum += v2 * x - v2;
                best = min(best, cur_sum);
            }
        }
    }
    cout << best << "\n";



    return 0;
}