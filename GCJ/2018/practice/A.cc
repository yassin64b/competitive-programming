#include <bits/stdc++.h>

using namespace std;

class gcj_number_guessing {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int A, B, N;
            in >> A >> B >> N;
            int low = A + 1, high = B;
            while (true) {
                int mid = (low + high) / 2;
                out << mid << "\n";
                out.flush();
                string ans;
                in >> ans;
                if (ans == "CORRECT") {
                    break;
                } else if (ans == "TOO_SMALL") {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_number_guessing solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
