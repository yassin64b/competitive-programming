#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n, A, B;
        in >> n >> A >> B;
        vector<int> s(n - 1);
        int first;
        in >> first;
        int sum = first;
        for (int i = 0; i < n - 1; ++i) {
            in >> s[i];
            sum += s[i];
        }
        sort(begin(s), end(s));
        reverse(begin(s), end(s));
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (first * A / sum >= B) {
                break;
            }
            sum -= s[i];
            ++res;
        }
        out << res << "\n";
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
