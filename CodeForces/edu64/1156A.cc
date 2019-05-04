#include <bits/stdc++.h>

using namespace std;

constexpr int CI = 1, TR = 2, SQ = 3; 
int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool fin = true;
    int res = 0;
    for (int i = 1; i < n; ++i) {
        set<int> s{a[i - 1], a[i]};
        if (s == set{TR, SQ}) {
            fin = false;
        } else if (s == set{TR, CI}) {
            res += 3;
        } else if (s == set{SQ, CI}) {
            res += 4;
        }
    }
    for (int i = 2; i < n; ++i) {
        if (a[i] == TR && a[i - 1] == CI && a[i - 2] == SQ) {
            --res;
        }
    }
    if (fin) {
        cout << "Finite\n" << res << "\n";
    } else {
        cout << "Infinite\n"; 
    }
    return 0;
}