#include <bits/stdc++.h>

using namespace std;

class A402 {
public:
    void solve(istream& in, ostream& out) {
        int k, a, b, v;
        in >> k >> a >> b >> v;
        int low = 0, high = a, ans = high;
        while (low <= high) {
            int num_box = (low + high) / 2;
            int num_div = min((k - 1) * num_box, b);
            int num_sect = num_box + num_div;
            int num_nuts = num_sect * v;
            if (num_nuts >= a) {
                ans = num_box;
                high = num_box - 1;
            } else {
                low = num_box + 1;
            }
        }
        out << ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    A402 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
