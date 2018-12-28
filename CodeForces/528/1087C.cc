#include <bits/stdc++.h>

using namespace std;

class TaskC {
private:
    void move_horizontal(int &curx, int &cury, pair<int, int> xy, set<pair<int, int>> &buy) {
        while (curx < xy.first) {
            ++curx;
            buy.emplace(curx, cury);
        }
    }
    void move_vertical(int &curx, int &cury, pair<int, int> xy, set<pair<int, int>> &buy) {
        while (cury != xy.second) {
            cury += (cury > xy.second ? -1 : 1);
            buy.emplace(curx, cury);
        }
    }
public:
    void solve(istream& in, ostream& out) {
        vector<pair<int, int>> xy(3);
        for (int i = 0; i < 3; ++i) {
            in >> xy[i].first >> xy[i].second;
        }
        sort(begin(xy), end(xy));
        int curx = xy[0].first, cury = xy[0].second;
        set<pair<int, int>> buy{{curx, cury}};
        for (int i = 1; i < 3; ++i) {
            if (i % 2 == 1) {
                move_horizontal(curx, cury, xy[i], buy);
                move_vertical(curx, cury, xy[i], buy);
            } else {
                move_vertical(curx, cury, xy[i], buy);
                move_horizontal(curx, cury, xy[i], buy);
            }
        }
        out << buy.size() << "\n";
        for (auto [x, y] : buy) {
            out << x << " " << y << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskC solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
