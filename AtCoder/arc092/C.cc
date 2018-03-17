#include <bits/stdc++.h>

using namespace std;

class arc092_c {
public:
    void solve(istream& in, ostream& out) {
        int N;
        in >> N;
        vector<int> a(N), b(N), c(N), d(N);
        vector<pair<int, int>> cd(N);
        for (int i = 0; i < N; ++i) {
            in >> a[i] >> b[i];
        }
        for (int i = 0; i < N; ++i) {
            in >> c[i] >> d[i];
            cd[i] = {c[i], d[i]};
        }
        sort(begin(cd), end(cd));
        int res = 0;
        for (int i = 0; i < N; ++i) {
            int ind = -1;
            for (int j = 0; j < N; ++j) {
                if (a[j] < cd[i].first && b[j] < cd[i].second) {
                    if (ind == -1 || b[j] > b[ind]) {
                        ind = j;
                    }
                }
            }
            if (ind != -1) {
                ++res;
                a[ind] = b[ind] = 3 * N;
            }
        }
        
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    arc092_c solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
