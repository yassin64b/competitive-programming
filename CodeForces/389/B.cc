/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author yassin64b
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

using namespace std;

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        string s, t;
        in >> s >> t;
        
        vector<string> res;
        map<char,char> seen;
        for (size_t i = 0; i < s.size(); ++i) {
            if (seen.find(t[i]) != seen.end()) {
                t[i] = seen[t[i]];

                if (t[i] != s[i]) {
                    out << -1 << endl;
                    return;
                } else {
                    continue;
                }
                
            } else if (t[i] != s[i]) {
                if (seen.find(s[i]) != seen.end()) {
                    out << -1 << endl;
                    return;
                }
                res.push_back(string(1, t[i]) + " " + s[i] + "\n");
                //out << string(1, t[i]) + " " + s[i] + "\n";
                seen[t[i]] = s[i];
                seen[s[i]] = t[i];
            } else {
                seen[t[i]] = s[i];
            }
        }
        
        out << res.size() << endl;
        for (string &tmp : res) {
            out << tmp;
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
