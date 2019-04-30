#include <bits/stdc++.h>

using namespace std;

void f(int x, set<int> &res) {
    ++x;
    while (x % 10 == 0) {
        x /= 10;
    }
    if (x <= 9) {
        for (int i = 1; i <= 9; ++i) {
            res.insert(i);
        }
    } else {
        res.insert(x);
        f(x, res);
    }
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    set<int> res{n};
    f(n, res);
    cout << res.size() << "\n";
    return 0;
}