#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    constexpr int MXV = 7'000;

    vector<int> sq_free(MXV + 1, 1);
    for (int i = 1; i <= MXV; ++i) {
        for (int j = 2; j * j <= i; ++j) {
            if (i % (j * j) == 0) {
                sq_free[i] = 0;
                break;
            }
        }
    }
    vector<bitset<MXV + 1>> div(MXV + 1), mob(MXV + 1);
    for (int x = 1; x <= MXV; ++x) {
        for (int i = 1; i <= x; ++i) {
            div[x][i] = (x % i == 0);
        }
    }
    for (int i = 1; i <= MXV; ++i) {
        for (int x = 1; x <= i; ++x) {
            mob[x][i] = (i % x == 0 && sq_free[i / x]);
        }
    }

    int n, q;
    cin >> n >> q;
    vector<bitset<MXV + 1>> sets(n);
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int x, v;
            cin >> x >> v;
            --x;
            sets[x] = div[v];
        } else if (t == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            --x; --y; --z;
            sets[x] = sets[y] ^ sets[z];
        } else if (t == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            --x; --y; --z;
            sets[x] = sets[y] & sets[z];
        } else {
            assert(t == 4);
            int x, v;
            cin >> x >> v;
            --x;
            bitset<MXV + 1> tmp = sets[x] & mob[v];
            cout << tmp.count() % 2 << "";
        }
    }

    return 0;
}