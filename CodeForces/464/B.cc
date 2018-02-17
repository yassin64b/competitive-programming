#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        long long N;
        int K;
        in >> N >> K;
        vector<long long> a(K);
        for (int i = 0; i < K; ++i) {
            in >> a[i];
        }
        int box = 0;
        long long num_ham = N - N % a[0];
        for (int i = 1; i < K; ++i) {
            if (N - N % a[i] > num_ham) {
                box = i;
                num_ham = N - N % a[i];
            }
        }
        out << box + 1 << " " << N / a[box] << "\n";
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
