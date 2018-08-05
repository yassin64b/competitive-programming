#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int m, n;
        cin >> m >> n;
        vector<int> p(n);
        int ans;
        for (int i = 0; i < n; ++i) {
            cout << m << "\n";
            cout.flush();
            cin >> ans;
            if (ans == 0) {
                return;
            }
            if (ans == -1) {
                p[i] = 1;
            } else {
                p[i] = 0;
            }
        }
        int i = 0;
        int low = 1, high = m - 1;
        while (true) {
            int mid = (low + high) / 2;
            cout << mid << "\n";
            cout.flush();
            cin >> ans;
            if (ans == 0) {
                return;
            } else if ((ans == -1 && p[i % n]) || (ans == 1 && !p[i % n])) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            ++i;
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
