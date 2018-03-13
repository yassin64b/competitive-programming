#include <bits/stdc++.h>

using namespace std;

class TaskE {
private:
    int cnt[10];
    void solve(const string &s, ostream &out) {
        int n = s.size();
        vector<int> pre_non_zero(n + 1);
        pre_non_zero[0] = 0;
        for (int i = 0; i < n; ++i) {
            pre_non_zero[i + 1] = pre_non_zero[i] + (s[i] > '0');
        }
        if (s[0] == '1' && pre_non_zero[n] == 1) { // 10000...
            out << string(n - 2, '9') << "\n";
            return;
        } else if (s[0] == '1' && s[n - 1] == '1' && pre_non_zero[n] == 2) { // 100...001
            out << string(n - 2, '9') << "\n";
            return;
        }
        string t;
        fill_n(cnt, 10, 0);
        for (int i = 0; i < n; ++i) {
            if (i < n - 1) {
                cnt[s[i] - '0'] ^= 1;
                if (check(s, i + 1, pre_non_zero)) { // ok to keep s[i]
                    t += s[i];
                    continue;
                }
                cnt[s[i] - '0'] ^= 1;
            }
            for (char c = s[i] - 1; c >= '0'; --c) { // check if char smaller than s[i] possible
                cnt[c - '0'] ^= 1;
                if (accumulate(begin(cnt), end(cnt), 0) <= n - (i + 1)) { // can fill the rest correctly
                    t += c;
                    fill_rest(t, i + 1, n);
                    break;
                }
                cnt[c - '0'] ^= 1;
            }
            break;
        }
        out << t << "\n";
    }
    bool check(const string &s, int ind, const vector<int> &pre_non_zero) {
        int c = accumulate(begin(cnt), end(cnt), 0), n = s.size();
        if (c > n - ind) { // not enough space to fix all odd occurences
            return false;
        } else if (pre_non_zero[n - c] - pre_non_zero[ind] > 0) {
            // non zero number in between end and beginning -> can make that one smaller + fix end arbitrarly
            return true;
        }
        // check if filling end increasingly with odd occ. is possible
        for (int i = n - c, nxt = 0; i < n; ++i, ++nxt) {
            while (cnt[nxt] == 0) {
                ++nxt;
            }
            if (s[i] > nxt + '0') {
                return true;
            } else if (s[i] < nxt + '0') {
                return false;
            }
        }
        return false;
    }
    void fill_rest(string &t, int ind, int n) { // t already smaller s
        int c = accumulate(begin(cnt), end(cnt), 0);
        t += string(n - ind - c, '9');
        int nxt = 9;
        while (nxt >= 0) { // fill end decreasingly with odd occ. (ok because number already smaller)
            while (nxt >= 0 && cnt[nxt] == 0) {
                --nxt;
            }
            if (nxt >= 0) {
                t += nxt + '0';
                --nxt;
            }
        }
    }
public:
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 0; t < T; ++t) {
            string s;
            in >> s;
            solve(s, out);
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
