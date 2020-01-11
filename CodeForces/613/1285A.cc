#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    int cnt_l = count(begin(s), end(s), 'L');
    int cnt_r = n - cnt_l;
    cout << cnt_r + cnt_l + 1 << "\n";

    return 0;
}