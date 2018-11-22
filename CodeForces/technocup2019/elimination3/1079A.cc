#include <bits/stdc++.h>

using namespace std;

class TaskA {
public:
    void solve(istream& in, ostream& out) {
        int n, k;
        in >> n >> k;
        vector<int> a(n), cnt(101, 0);
        set<int> types;
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            ++cnt[a[i]];
            types.insert(a[i]);
        }
        int mx = *max_element(begin(cnt), end(cnt));
        int mn_num_dishes = (mx + k - 1) / k;
        out << mn_num_dishes * k * (int)types.size() - n << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskA solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
