#include <bits/stdc++.h>

using namespace std;

class gcj_1b_b {
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int S;
            in >> S;
            vector<int> D(S), A(S), B(S);
            for (int i = 0; i < S; ++i) {
                in >> D[i] >> A[i] >> B[i];
            }
            int mx = 0, sz = 0;
            for (int i = 0; i < S && i + mx <= S; ++i) {
                int M = D[i] + A[i], N;
                bool found_N = false, ok = true;
                int last_to = -1;
                for (int k = i; ok && k < S; ++k) {
                    if (D[k] + A[k] != M) {
                        if (!found_N) {
                            found_N = true;
                            N = D[k] - B[k];
                        } else {
                            if (D[k] - B[k] != N) {
                                ok = false;
                            }
                        }
                    }
    
                    if (ok) {
                        last_to = k;
                        int len = k - i + 1;
                        if (len > mx) {
                            mx = len;
                            sz = 1;
                        } else if (len == mx) {
                            ++sz;
                        }
                    }
                }
                
                ok = true;
                N = D[i] - B[i];
                bool found_M = false;
                for (int k = i; ok && k < S; ++k) {
                    if (D[k] - B[k] != N) {
                        if (!found_M) {
                            found_M = true;
                            M = D[k] + A[k];
                        } else {
                            if (D[k] + A[k] != M) {
                                ok = false;
                            }
                        }
                    }
                    if (ok && k > last_to) {
                        int len = k - i + 1;
                        if (len > mx) {
                            mx = len;
                            sz = 1;
                        } else if (len == mx) {
                            ++sz;
                        }
                    }
                }
            }
            out << "Case #" << t << ": " << mx << " " << sz << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_1b_b solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
