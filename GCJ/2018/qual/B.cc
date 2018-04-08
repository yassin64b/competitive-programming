#include <bits/stdc++.h>

using namespace std;

class gcj_trouble_sort {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<int> V(N), even, odd;
            for (int i = 0; i < N; ++i) {
                in >> V[i];
                if (i % 2) {
                    odd.push_back(V[i]);
                } else {
                    even.push_back(V[i]);
                }
            }
            sort(begin(even), end(even));
            sort(begin(odd), end(odd));
            vector<int> res(N);
            for (int i = 0, j = 0, k = 0; i < N; ++i) {
                if (i % 2) {
                    res[i] = odd[k++];
                } else {
                    res[i] = even[j++];
                }
            }
            int ans = -1;
            for (int i = 0; i + 1 < N; ++i) {
                if (res[i] > res[i + 1]) {
                    ans = i;
                    break;
                }
            }
            out << "Case #" << t << ": ";
            if (ans == -1) {
                out << "OK\n";
            } else {
                out << ans << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_trouble_sort solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
