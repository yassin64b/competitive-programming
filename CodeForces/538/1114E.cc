#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    int mx = 0;
    vector<int> vals;
    if (n <= 60) {
        for (int i = 1; i <= n; ++i) {
            cout << "? " << i << "\n";
            cout.flush();
            int r;
            cin >> r;
            assert(r != -1);
            vals.push_back(r);
            mx = max(mx, r);
        }
    } else {
        int num_left = 60;
        int low = 1, high = 1'000'000'000;
        while (low <= high) {
            int mid = (low + high) / 2;
            cout << "> " << mid - 1 << "\n";
            cout.flush();
            int r;
            cin >> r;
            --num_left;
            assert(r != -1);
            if (r == 1) {
                low = mid + 1;
                mx = mid;
            } else {
                high = mid - 1;
            }
        }

        auto now = chrono::system_clock::now();
        auto now_ms = chrono::time_point_cast<chrono::milliseconds>(now);
        auto epoch = now_ms.time_since_epoch();
        auto value = chrono::duration_cast<chrono::milliseconds>(epoch);
        mt19937 gen(value.count());
        uniform_int_distribution<int> dis(1, n);
        set<int> vis;
        for (int i = 0; i < num_left; ++i) {
            int ind = dis(gen);
            while (vis.count(ind)) {
                ind = dis(gen);
            }
            vis.insert(ind);

            cout << "? " << ind << "\n";
            cout.flush();
            int r;
            cin >> r;
            assert(r != -1);
            vals.push_back(r);
        }
    }


    vector<int> diff;
    for (int x : vals) {
        for (int y : vals) {
            if (x > y) {
                diff.push_back(x - y);
            }
        }
    }
    
    int d = diff[0];
    for (int x : diff) {
        d = gcd(d, x);
    }
    int x1 = mx - (n - 1) * d;
    cout << "! " << x1 << " " << d << "\n";
    cout.flush();   

    return 0;
}