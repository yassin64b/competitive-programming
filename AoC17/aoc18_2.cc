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

class aoc18_2 {
public:
    void solve(istream& in, ostream& out) {
        vector<tuple<string, string, string>> v;
        string s;
        while (getline(in, s)) {
            stringstream ss(s);
            string com, X;
            ss >> com >> X;
            if (com == "snd" || com == "rcv") {
                v.emplace_back(com, X, ""s);
            } else {
                string Y;
                ss >> Y;
                v.emplace_back(com, X, Y);
            }
        }
        map<string, long long> reg[2]{};
        for (int id = 0; id <= 1; ++id) {
            for (char c = 'a'; c <= 'z'; ++c) {
                reg[id][""s + c] = (c == 'p' ? id : 0);
            }
        }
        int res = 0;
        queue<long long> q[2]{};
        long long ins[2]{};
        bool locked[2]{};
        while (!((locked[0] || ins[0] >= (int)v.size())
                 && (locked[1] || ins[1] >= (int)v.size()))) {
            for (int id = 0; id <= 1; ++id) {
                if (ins[id] >= (int)v.size()) continue;
                long long& i = ins[id];
                //cout << id << " " << i << endl;
                string com, X, Y;
                tie(com, X, Y) = v[i];
                if (com == "snd") {
                    if (reg[id].find(X) == reg[id].end()) {
                        q[1 - id].push(stoll(X));
                    } else {
                        q[1 - id].push(reg[id][X]);
                    }
                    //cout << id << " send " << q[1 - id].front() << endl;
                    if (id)
                        ++res;
                } else if (com == "set") {
                    if (reg[id].find(Y) == reg[id].end()) {
                        reg[id][X] = stoll(Y);
                    } else {
                        reg[id][X] = reg[id][Y];
                    }
                } else if (com == "add") {
                    if (reg[id].find(Y) == reg[id].end()) {
                        reg[id][X] += stoll(Y);
                    } else {
                        reg[id][X] += reg[id][Y];
                    }
                } else if (com == "mul") {
                    if (reg[id].find(Y) == reg[id].end()) {
                        reg[id][X] *= stoll(Y);
                    } else {
                        reg[id][X] *= reg[id][Y];
                    }
                } else if (com == "mod") {
                    if (reg[id].find(Y) == reg[id].end()) {
                        reg[id][X] %= stoll(Y);
                    } else {
                        reg[id][X] %= reg[id][Y];
                    }
                } else if (com == "rcv") {
                    if (q[id].empty()) {
                        --i;
                        //cout << id << " locked" << endl;
                        locked[id] = true;
                    } else {
                        reg[id][X] = q[id].front();
                        q[id].pop();
                        //cout << id << " recv " << reg[id][X] << endl;
                        locked[id] = false;
                    }
                } else if (com == "jgz") {
                    long long val;
                    if (reg[id].find(X) == reg[id].end()) {
                        val = stoll(X);
                    } else {
                        val = reg[id][X];
                    }
                    if (val > 0) {
                        if (reg[id].find(Y) == reg[id].end()) {
                            i += stoll(Y) - 1;
                        } else {
                            i += reg[id][Y] - 1;
                        }
                    }
                }
                ++i;
            }
            //cout << "res: " << res << endl;
        }
        out << res << endl;
    }
};


int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    aoc18_2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
