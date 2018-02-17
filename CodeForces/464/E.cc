#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int Q;
        in >> Q;
        vector<int> nums;
        double sum = 0;
        for (int q = 0, ind = 0; q < Q; ++q) {
            int type;
            in >> type;
            if (type == 1) {
                int x;
                in >> x;
                nums.push_back(x);
            } else {
                assert(type == 2);
                while (ind + 1 < (int)nums.size()) {
                    double mx = nums.back() - (sum + nums.back()) / (ind + 1);
                    double n_mx = nums.back() - (sum + nums[ind] + nums.back()) / (ind + 2);
                    if (n_mx + 1e-8 < mx) {
                        break;
                    } else {
                        sum += nums[ind];
                        ++ind;
                    }
                }
                out.precision(10);
                out << fixed << nums.back() - (sum + nums.back()) / (ind + 1) << "\n";
            }
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
