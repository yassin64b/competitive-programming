#include <bits/stdc++.h>

using namespace std;

long long count_inversions(int *a, int n) {
    if (n <= 1) {
        return 0;
    }
    int sz1 = n / 2, sz2 = n - sz1;
    long long inv1 = count_inversions(a, sz1);
    long long inv2 = count_inversions(a + sz1, sz2);
    vector<int> old1(a, a + sz1), old2(a + sz1, a + n);
    int k = 0, i = 0, j = 0;
    long long inv = inv1 + inv2;
    while (i < sz1 && j < sz2) {
        if (old1[i] <= old2[j]) {
            a[k++] = old1[i++];
            inv += j;
        } else {
            a[k++] = old2[j++];
        }
    }
    while (i < sz1) {
        a[k++] = old1[i++];
        inv += j; //j == n - m
    }
    while (j < sz2) {
        a[k++] = old2[j++];
    }
    return inv % 2;
}

class TaskB {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        int p[1'000'000];
        for (int i = 0; i < n; ++i) {
            in >> p[i];
        }
        bool petr = count_inversions(&p[0], n) % 2 == n % 2;
        out << (petr ? "Petr" : "Um_nik") << "\n";
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
