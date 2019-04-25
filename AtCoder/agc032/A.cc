#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N;
    cin >> N;
    vector<int> b(N);
    for (int i = 0; i < N; ++i) {
        cin >> b[i];
    }
    vector<int> res;
    for (int i = 0; i < N; ++i) {
        bool found = false;
        for (int j = (int)b.size() - 1; j >= 0; --j) {
            if (b[j] == j + 1) {
                b.erase(b.begin() + j);
                res.push_back(j + 1);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << -1 << "\n";
            return 0;
        }
    }
    reverse(begin(res), end(res));
    for (int x : res) {
        cout << x << "\n";
    }


    return 0;
}