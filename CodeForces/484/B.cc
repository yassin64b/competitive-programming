#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<pair<int, int>> w(n);
        for (int i = 0; i < n; ++i) {
            in >> w[i].first;
            w[i].second = i;
        }
        string s;
        in >> s;
        sort(begin(w), end(w));
        vector<pair<int, int>> tmp;
        vector<int> res;
        for (int i = 0, j = 0; i < 2 * n; ++i) {
            if (s[i] == '0') {
                tmp.push_back(w[j]);
                res.push_back(w[j].second);
                ++j;
            } else {
                res.push_back(tmp.back().second);
                tmp.pop_back();
            }
        }
        for (int x : res) {
            out << x + 1 << " ";
        }
        out << "\n";
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
