#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N, Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    vector<char> t(Q), d(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> t[i] >> d[i];
    }

    int low = 1, high = N, ans1 = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int i = mid - 1;
        for (int j = 0; i >= 0 && i < N && j < Q; ++j) {
            if (t[j] == s[i]) {
                i += (d[j] == 'L' ? -1 : 1);
            }
        }
        if (i < 0) {
            ans1 = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    
    low = 1, high = N;
    int ans2 = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int i = N - mid;
        for (int j = 0; i >= 0 && i < N && j < Q; ++j) {
            if (t[j] == s[i]) {
                i += (d[j] == 'L' ? -1 : 1);
            }
        }
        if (i >= N) {
            ans2 = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << N - (ans1 + ans2) << "\n";


    return 0;
}