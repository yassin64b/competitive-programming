#include <bits/stdc++.h>

using namespace std;

class tle17c6p3 {
public:
    void solve(istream& in, ostream& out) {
        long long N;
        in >> N;
        vector<long long> res;
        long long sum = 0;
        for (int i = 0; sum + (1LL << i) <= N; ++i) {
            res.push_back(1LL << i);
            sum += res.back();
        }
        if (sum < N) res.push_back(N - sum);
        out << res.size() << "\n";
        sort(begin(res), end(res));
        for (long long x : res) out << x << " ";
        out << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    tle17c6p3 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
