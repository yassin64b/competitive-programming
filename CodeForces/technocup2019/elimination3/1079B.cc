#include <bits/stdc++.h>

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        string s;
        in >> s;
        int n = s.size();
        for (int a = 1; a <= 5; ++a) {
            for (int b = 1; b <= 20; ++b) {
                int num_chars = a * b;
                int num_asterisk = num_chars - n;
                if (num_asterisk >= 0) {
                    vector<int> num_a_row(a, num_asterisk / a);
                    int sum = accumulate(begin(num_a_row), end(num_a_row), 0);
                    for (int i = 0; i < a; ++i) {
                        if (sum < num_asterisk) {
                            ++num_a_row[i];
                            ++sum;
                        }
                    }
                    if (sum == num_asterisk) {
                        out << a << " " << b << "\n";
                        for (int i = 0, j = 0; i < a; ++i) {
                            out << string(num_a_row[i], '*');
                            out << s.substr(j, b - num_a_row[i]);
                            j += b - num_a_row[i];
                            out << "\n";
                        }
                        return;
                    }
                }
            }
        }
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
