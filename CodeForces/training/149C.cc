/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <tuple>
#include <queue>
#include <functional>
#include <stack>
#include <numeric>
#include <cassert>
#include <sstream>

using namespace std;

class C149 {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a.begin(), a.end(), greater<pair<int, int>>());
        /*int mx_len = n / 2 + n % 2;
        vector<int> p, q;
        int sum_p = 0, sum_q = 0;
        for (int i = 0; i < n; ++i) {
            int x = p.size(), y = q.size();
            if (x < mx_len && y < mx_len) {
                if (sum_p < sum_q) {
                    p.push_back(a[i].second);
                    sum_p += a[i].first;
                } else if (sum_p > sum_q) {
                    q.push_back(a[i].second);
                    sum_q += a[i].first;
                } else {
                    if (x < y) {
                        p.push_back(a[i].second);
                        sum_p += a[i].first;
                    } else {
                        q.push_back(a[i].second);
                        sum_q += a[i].first;
                    }
                }
            } else if (x < mx_len) {
                p.push_back(a[i].second);
                sum_p += a[i].first;
            } else {
                assert(y < mx_len);
                q.push_back(a[i].second);
                sum_q += a[i].first;
            }
        }
        out << p.size() << "\n";
        for (int z : p) {
            out << z << " ";
        }
        out << "\n" << q.size() << "\n";
        for (int z : q) {
            out << z << " ";
        }
        out << "\n";*/
        out << n / 2 + n % 2 << "\n";
        for (int i = 0; i < n; i += 2) {
            out << a[i].second << " ";
        }
        out << "\n" << n / 2 << "\n";
        for (int i = 1; i < n; i += 2) {
            out << a[i].second << " ";
        }
        out << "\n";
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    C149 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
