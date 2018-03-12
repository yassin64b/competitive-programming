#include <bits/stdc++.h>

using namespace std;

class TaskB {
private:
    int get_level(int a, int b, int i, int j, int cur) {
        int mid = (i + j) / 2;
        if (a <= mid && b <= mid) {
            return get_level(a, b, i, mid, cur - 1);
        } else if (a > mid && b > mid) {
            return get_level(a, b, mid + 1, j, cur - 1);
        } else {
            return cur;
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, a, b;
        in >> n >> a >> b;
        int p;
        for (p = 0; (1 << p) < n; ++p);
        assert((1 << p) == n);
        int level = get_level(a, b, 1, n, p);
        if (level == p) {
            out << "Final!\n";
        } else {
            out << level << "\n";
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
