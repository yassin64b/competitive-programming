#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int w, l;
        in >> w >> l;
        vector<int> a(w + 1);
        map<int, int> m;
        for (int i = 1; i < w; ++i) {
            in >> a[i];
            m[i] = a[i];
        }
        m[w] = 1'000'000'000;
        vector<int> num(w + 1, 0);
        for (int i = 1; i <= l; ++i) {
            num[i] = a[i];
            a[i] = 0;
            m.erase(i);
        }
        for (int i = 1; i < w; ++i) {
            if (num[i]) {
                auto it = m.upper_bound(i + l);
                if (it == m.begin()) continue;
                --it;
                while (num[i]) {
                    int send = min(num[i], it->second);
                    num[i] -= send;
                    it->second -= send;
                    num[it->first] += send;
                    if (it == m.begin()) break;
                    if (it->second == 0)
                        it = m.erase(it);
                    --it;
                }
            }
        }
        out << num[w] << "\n";
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
