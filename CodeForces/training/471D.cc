#include <bits/stdc++.h>

using namespace std;

// taken from https://cp-algorithms.com/string/z-function.html
vector<int> z_function(const vector<int> &s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

class D471 {
public:
    void solve(istream& in, ostream& out) {
        int n, w;
        in >> n >> w;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
        }
        vector<int> b(w);
        for (int i = 0; i < w; ++i) {
            in >> b[i];
        }
        if (w == 1) {
            out << n << "\n";
            return;
        }
        vector<int> s;
        for (int i = 0; i + 1 < w; ++i) {
            s.push_back(b[i + 1] - b[i]);
        }
        for (int i = 0; i + 1 < n; ++i) {
            s.push_back(a[i + 1] - a[i]);
        }
        vector<int> z(z_function(s));
        int cnt = 0;
        for (int i = w - 1; i < (int)s.size(); ++i) {
            cnt += (z[i] >= w - 1);
        }
        out << cnt << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    D471 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
