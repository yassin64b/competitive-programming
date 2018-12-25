#include <bits/stdc++.h>

using namespace std;

class TaskD {
private:
    int query(int c, int d) {
        cout << "? " << c << " " << d << endl;
        int ans;
        cin >> ans;
        if (ans == -2) {
            exit(0);
        } else {
            return ans;
        }
    }
public:
    // a        b        ans1 ans2
    // 0greater 0smaller -1   1
    // 0smaller 0greater -1   1
    // 0greater 1smaller  1   1
    // 0smaller 1greater -1   -1
    // 1greater 0smaller  1   1
    // 1smaller 0greater -1   -1
    // 1greater 1smaller  1   -1
    // 1smaller 1greater  1   -1
    
    // 0equal 0equal -> -1 1
    // 1equal 0equal -> 0 0
    // 0equal 1equal -> 0 0
    // 1equal 1equal -> 1 -1
    
    void solve(istream& in, ostream& out) {
        int greater = query(0, 0);
        int a = 0, b = 0;
        for (int shift = 29; shift >= 0; --shift) {
            int c1 = a;
            int d1 = b | (1 << shift);
            int ans1 = query(c1, d1);
            
            int c2 = a | (1 << shift);
            int d2 = b;
            int ans2 = query(c2, d2);
            
            if (ans1 != ans2) {
                assert(ans1 != 0 && ans2 != 0);
                if (ans1 == 1) {
                    a |= (1 << shift);
                    b |= (1 << shift);
                }
            } else {
                assert(greater != 0);
                if (greater == 1) {
                    a |= (1 << shift);
                } else if (greater == -1) {
                    b |= (1 << shift);
                }
                if (ans1 == 1) {
                    greater = 1;
                } else if (ans1 == -1) {
                    greater = -1;
                } else {
                    greater = 0;
                }
            }
        }
        cout << "! " << a << " " << b << "\n";
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
