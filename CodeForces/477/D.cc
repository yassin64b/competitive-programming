#include <bits/stdc++.h>

using namespace std;

class TaskD {
private:
     void calc(int x1, int x2, const vector<pair<int, int>> &c,
               vector<int> &v1, vector<int> &v2, int n)
     {
        int end1 = n;
        for (int i = 0; i < n; ++i) {
            int k = (x1 + c[i].first - 1) / c[i].first;
            end1 = min(end1, i + k - 1);
        }
        int end2 = n;
        for (int j = end1 + 1; j < n; ++j) {
            int k = (x2 + c[j].first - 1) / c[j].first;
            end2 = min(end2, j + k - 1);
        }
        if (end1 < n && end2 < n) {
            for (int i = 0; i < n; ++i) {
                int k = (x1 + c[i].first - 1) / c[i].first;
                if (end1 == i + k - 1) {
                    for (int z = i; z <= i + k - 1; ++z) {
                        v1.push_back(c[z].second);
                    }
                    break;
                }
            }
            for (int j = end1 + 1; j < n; ++j) {
                int k = (x2 + c[j].first - 1) / c[j].first;
                if (end2 == j + k - 1) {
                    for (int z = j; z <= j + k - 1; ++z) {
                        v2.push_back(c[z].second);
                    }
                    break;
                }
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int n, x1, x2;
        in >> n >> x1 >> x2;
        vector<pair<int, int>> c(n);
        for (int i = 0; i < n; ++i) {
            in >> c[i].first;
            c[i].second = i + 1;
        }
        sort(begin(c), end(c));
        
        vector<int> v1, v2;
        calc(x1, x2, c, v1, v2, n);
        if (v1.empty()) {
            calc(x2, x1, c, v2, v1, n);
        }
        
        if (v1.empty()) {
            out << "No\n";
        } else {
            out << "Yes\n";
            out << v1.size() << " " << v2.size() << "\n";
            for (int x : v1) {
                out << x << " ";
            }
            out << "\n";
            for (int x : v2) {
                out << x << " ";
            }
            out << "\n";
        }
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
