#include <bits/stdc++.h>

using namespace std;

class snowboots2 {
public:
    void solve(istream& in, ostream& out) {
        int N, B;
        in >> N >> B;
        vector<pair<int, int>> f(N);
        for (int i = 0; i < N; ++i) {
            in >> f[i].first;
            f[i].second = i;
        }
        vector<pair<pair<int, int>, int>> boots(B);
        for (int i = 0; i < B; ++i) {
            in >> boots[i].first.first >> boots[i].first.second;
            boots[i].second = i;
        }
        sort(begin(f) + 1, begin(f) + N - 1);
        sort(begin(boots), end(boots));
        set<int> act;
        act.insert(0);
        act.insert(N - 1);
        multiset<int> dist;
        dist.insert(N - 1);
        vector<int> res(B, 0);
        for (int i = 0, j = 1; i < B; ++i) {
            int mx = boots[i].first.first;
            while (j < N - 1 && f[j].first <= mx) {
                //cout << "find " << f[j].second << endl;
                auto it1 = act.upper_bound(f[j].second);
                assert(it1 != begin(act));
                assert(it1 != end(act));
                auto it2 = it1; --it2;
                int d = *it1 - *it2;
                dist.erase(dist.find(d));
                dist.insert(*it1 - f[j].second);
                dist.insert(f[j].second - *it2);
                act.insert(f[j].second);
                //cout << "act " << f[j].second << endl;
                ++j;
            }
            res[boots[i].second] = (*dist.rbegin() <= boots[i].first.second);
        }
        for (int x : res) {
            out << x << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    snowboots2 solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
