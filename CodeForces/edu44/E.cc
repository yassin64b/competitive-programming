#include <bits/stdc++.h>

using namespace std;

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n, k, d;
        in >> n >> k >> d;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        sort(begin(a), end(a));
        queue<int> q;
        q.push(0);
        for (int i = 1; i < n; ++i) {
            if (!q.empty() && i - q.front() >= k) {
                q.push(i);
            }
            while (!q.empty() && a[i] - a[q.front()] > d) {
                q.pop();
            }
        }
        if (q.empty() || n - q.front() < k) {
            out << "NO\n";
        } else {
            out << "YES" << "\n";
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
