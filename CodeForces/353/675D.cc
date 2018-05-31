#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        in >> a[0];
        set<int> cur;
        map<int, int> h;
        cur.insert(a[0]);
        h[a[0]] = 1;
        for (int i = 1; i < n; ++i) {
            in >> a[i];
            auto it1 = cur.upper_bound(a[i]);
            if (it1 != cur.begin() && it1 != cur.end()) {
                auto it2 = it1;
                --it2;
                if (h[*it1] < h[*it2]) {
                    swap(it1, it2);
                }
                out << *it1 << " ";
                h[a[i]] = h[*it1] + 1;
            } else if (it1 != cur.begin()) {
                --it1;
                out << *it1 << " ";
                h[a[i]] = h[*it1] + 1;
            } else {
                out << *it1 << " ";
                h[a[i]] = h[*it1] + 1;
            }
            cur.insert(a[i]);
        }
        out << "\n";
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
