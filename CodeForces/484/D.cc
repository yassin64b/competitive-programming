#include <bits/stdc++.h>

using namespace std;

class TaskD {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<int> a(n);
        vector<pair<int, int>> b(n);
        for (int i = 0; i < n; ++i) {
            in >> a[i];
            b[i] = {a[i], i};
        }
        sort(begin(b), end(b));
        vector<pair<int, int>> segs;
        map<int, int> m;
        map<int, int> cnt;
        int num_segs = 0;
        int mx_loc = 0, mn_k = 0;
        for (int i = 0; i < n; ++i) {
            int val = b[i].first, ind = b[i].second;
            if (m.count(ind - 1) && m.count(ind + 1)) {
                --num_segs;
                int j1 = m[ind - 1], j2 = m[ind + 1];
                int sz1 = segs[j1].second - segs[j1].first + 1;
                int sz2 = segs[j2].second - segs[j2].first + 1;
                if (--cnt[sz1] == 0) cnt.erase(sz1);
                if (--cnt[sz2] == 0) cnt.erase(sz2);
                segs[j1].second = segs[j2].second;
                int seg_sz = sz1 + sz2 + 1;
                ++cnt[seg_sz];
                m[segs[j2].second] = j1;
            } else if (m.count(ind - 1)) {
                int j = m[ind - 1];
                int seg_sz = segs[j].second - segs[j].first + 1;
                if (--cnt[seg_sz] == 0) {
                    cnt.erase(seg_sz);
                }
                segs[j].second = ind;
                ++seg_sz;
                ++cnt[seg_sz];
                m[ind] = j;
            } else if (m.count(ind + 1)) {
                int j = m[ind + 1];
                int seg_sz = segs[j].second - segs[j].first + 1;
                if (--cnt[seg_sz] == 0) {
                    cnt.erase(seg_sz);
                }
                segs[j].first = ind;
                ++seg_sz;
                ++cnt[seg_sz];
                m[ind] = j;
            } else {
                segs.emplace_back(ind, ind);
                m[ind] = (int)segs.size() - 1;
                ++cnt[1];
                ++num_segs;
            }
            if (cnt.size() == 1U) {
                if (num_segs > mx_loc) {
                    mn_k = val + 1;
                    mx_loc = num_segs;
                }
            }
        }
        out << mn_k << "\n";
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
