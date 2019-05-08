#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> s(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }   
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int buy_price = *min_element(begin(s), end(s));
    int sell_price = *max_element(begin(b), end(b));
    if (buy_price >= sell_price) {
        cout << r << "\n";
    } else {
        int buy_cnt = r / buy_price;
        cout << r + buy_cnt * (sell_price - buy_price) << "\n";
    }
    return 0;
}