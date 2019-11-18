#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        cout << "Case #" << t << ": ";
        multiset<int> greater;
        int cur = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] > cur) {
                greater.insert(A[i]);
            }
            if ((int)greater.size() > cur) {
                ++cur;
                for (auto it = begin(greater); it != end(greater); ) {
                    if (*it <= cur) {
                        it = greater.erase(it);
                    } else {
                        break;
                    }
                }
            }
            cout << cur << " ";
        }
        cout << "\n";
    }


    return 0;
}