#include <bits/stdc++.h>

using namespace std;

class gcj_senate_evacuation {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<pair<int, char>> P(N);
            for (int i = 0; i < N; ++i) {
                in >> P[i].first;
                P[i].second = i + 'A';
            }
            sort(begin(P), end(P));
            reverse(begin(P), end(P));
            out << "Case #" << t << ":";
            while (P[0].first > P[1].first) {
                --P[0].first;
                out << " " << P[0].second;
            }
            for (int i = 2; i < N; ++i) {
                while (P[i].first--) {
                    out << " " << P[i].second;
                }
            }
            while (P[0].first--) {
                out << " " << P[0].second << P[1].second;
            }
            out << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_senate_evacuation solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
