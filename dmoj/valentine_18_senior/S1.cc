#include <bits/stdc++.h>

using namespace std;

class dmoj_val_1 {
public:
    void solve(istream& in, ostream& out) {
        int N, M;
        in >> N >> M;
        int res = 0, num = 0;
        for (int i = 0; i < 10'000; ++i) {
            string a = to_string(i);
            string b = a;
            string c = a;
            c.pop_back();
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            int ab = stoi(a + b);
            int ac = stoi(a + c);
            if (ab >= N && ab < M) {
                int cost = min(ab - N, M - ab);
                if (cost > res) {
                    res = cost;
                    num = ab;
                }
            }
            if (ac >= N && ac < M) {
                int cost = min(ac - N, M - ac);
                if (cost > res) {
                    res = cost;
                    num = ac;
                }
            }
        }
        out << num << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    dmoj_val_1 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
