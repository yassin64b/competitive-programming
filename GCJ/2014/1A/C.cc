#include <bits/stdc++.h>

using namespace std;

class gcj_proper_shuffle {
private:
    int count(const vector<int> &p, int N) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            cnt += (p[i] <= i);
        }
        return cnt;
    }
public:
    int test() {
        auto now = chrono::system_clock::now();
        auto now_ms = chrono::time_point_cast<chrono::milliseconds>(now);
        auto epoch = now_ms.time_since_epoch();
        auto value = chrono::duration_cast<chrono::milliseconds>(epoch);
        mt19937 gen(value.count());

        int N = 1000;
        vector<int> p(N);
        for (int i = 0; i < N; ++i) {
            p[i] = i;
        }
        int total = 0;
        vector<int> r1, r2;
        for (int t = 0; t < 120; ++t) { // good
            vector<int> a(p);
            for (int i = 0; i < N; ++i) {
                uniform_int_distribution<int> dis(i, N - 1);
                int k = dis(gen);
                swap(a[i], a[k]);
            }
            int cnt = count(a, N);
            cout << cnt << ": ";
            total += cnt;
            r1.push_back(cnt);
        }
        cout << endl << total << endl;
        total = 0;
        for (int t = 0; t < 120; ++t) { // bad
            vector<int> a(p);
            for (int i = 0; i < N; ++i) {
                uniform_int_distribution<int> dis(0, N - 1);
                int k = dis(gen);
                swap(a[i], a[k]);
            }
            int cnt = count(a, N);
            cout << cnt << ": ";
            total += cnt;
            r2.push_back(cnt);
        }
        int best = 240, cnt = -1;
        cout << endl << total << endl;
        for (int j = 0; j <= 1000; ++j) {
            int wrong = 0;
            for (int i = 0; i < 120; ++i) {
                wrong += r1[i] <= j;
                wrong += r2[i] > j;
            }
            if (wrong < best) {
                best = wrong;
                cnt = j;
            }
        }
        cout << endl;
        cout << best << " " << cnt << endl;
        return best;
    }
    void solve(istream& in, ostream& out) {
        int T;
        in >> T;
        for (int t = 1; t <= T; ++t) {
            int N;
            in >> N;
            vector<int> p(N);
            for (int i = 0; i < N; ++i) {
                in >> p[i];
            }
            int cnt = count(p, N);
            //cout << cnt << endl;
            out << "Case #" << t << ": ";
            out << (cnt <= 484 ? "BAD" : "GOOD") << "\n";
        }
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    gcj_proper_shuffle solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    //solver.test();
    return 0;
}
