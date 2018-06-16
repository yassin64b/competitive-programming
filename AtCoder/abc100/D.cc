#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

struct cake {
    i64 x, y, z;
};

class abc100d {
private:
    void update(const vector<cake> &v, int M, i64 &res) {
        i64 x = 0, y = 0, z = 0;
        for (int i = 0; i < M; ++i) {
            x += v[i].x; y += v[i].y; z += v[i].z;
        }
        res = max(res, abs(x) + abs(y) + abs(z));
    }
public:
    void solve(istream& in, ostream& out) {
        int N, M;
        in >> N >> M;
        vector<cake> v(N);
        for (int i = 0; i < N; ++i) {
            in >> v[i].x >> v[i].y >> v[i].z;
        }
        i64 res = 0;
        sort(begin(v), end(v), [](const cake &lhs, const cake &rhs) {
            return lhs.x + lhs.y + lhs.z < rhs.x + rhs.y + rhs.z;
        });
        update(v, M, res);
        sort(begin(v), end(v), [](const cake &lhs, const cake &rhs) {
            return lhs.x + lhs.y - lhs.z < rhs.x + rhs.y - rhs.z;
        });
        update(v, M, res);
        sort(begin(v), end(v), [](const cake &lhs, const cake &rhs) {
            return lhs.x - lhs.y + lhs.z < rhs.x - rhs.y + rhs.z;
        });
        update(v, M, res);
        sort(begin(v), end(v), [](const cake &lhs, const cake &rhs) {
            return lhs.x - lhs.y - lhs.z < rhs.x - rhs.y - rhs.z;
        });
        update(v, M, res);
        sort(begin(v), end(v), [](const cake &lhs, const cake &rhs) {
            return -lhs.x + lhs.y + lhs.z < -rhs.x + rhs.y + rhs.z;
        });
        update(v, M, res);
        sort(begin(v), end(v), [](const cake &lhs, const cake &rhs) {
            return -lhs.x + lhs.y - lhs.z < -rhs.x + rhs.y - rhs.z;
        });
        update(v, M, res);
        sort(begin(v), end(v), [](const cake &lhs, const cake &rhs) {
            return -lhs.x - lhs.y + lhs.z < -rhs.x - rhs.y + rhs.z;
        });
        update(v, M, res);
        sort(begin(v), end(v), [](const cake &lhs, const cake &rhs) {
            return -lhs.x - lhs.y - lhs.z < -rhs.x - rhs.y - rhs.z;
        });
        update(v, M, res);
        out << res << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    abc100d solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
