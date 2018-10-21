#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        map<int, int> cnt;
        long long ans = 0;
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            int ca = a[i] ^ ((1 << k) - 1);
            int v1 = sum ^ a[i], v2 = sum ^ ca;
            if (cnt[v1] + (v1 == 0) > cnt[v2] + (v2 == 0)) {
                a[i] = ca;
            }
            sum ^= a[i];
            ans += cnt[sum];
            ans += (sum == 0);
            ++cnt[sum];
        }
        out << 1LL * n * (n - 1) / 2 + n - ans << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskD solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
