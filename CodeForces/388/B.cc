#include <fstream>

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class TaskB {
public:
    void solve(std::istream& in, std::ostream& out) {
        int x1, y1, x2, y2, x3, y3;
        in >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        vector<pair<int,int>> res;
        for (int x4 = -3000; x4 <= 3000; ++x4) {
            for (int y4 = -3000; y4 <= 3000; ++y4) {
                if (!(x1 == x2 && x2 == x4 || x2 == x3 && x3 == x4 || x1 == x3 && x3 == x4
                        || y1 == y2 && y2 == y4 || y2 == y3 && y3 == y4 || y1 == y3 && y3 == y4) &&
                        (x2 - x1 == x3 - x4 && y2 - y1 == y3 - y4 ||
                        x3 - x1 == x2 - x4 && y3 - y1 == y2 - y4 ||
                        x3 - x1 == x4 - x2 && y3 - y1 == y4 - y2)) {
                    res.push_back({x4, y4});
                }
            }
        }

        out << res.size() << endl;
        for (auto &p : res) {
            out << p.first << " " << p.second << endl;
        }
    }
};


int main() {
    std::ios::sync_with_stdio(false);

    TaskB solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}