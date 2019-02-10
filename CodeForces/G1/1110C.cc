#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}


int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; ++q) {
        int a;
        cin >> a;
        int b = 0;
        for (int i = 0; i < 25; ++i) {
            if (!(a & (1 << i)) && (b | (1 << i)) < a) {
                b |= (1 << i);
            }
        }
        if (b == 0) {
            for (int d = 2; d * d <= a; ++d) {
                if (a % d == 0) {
                    b = a / d;
                    break;
                }
            }
            if (b == 0) {
                b = 1;
            }
        }
        cout << gcd(a ^ b, a & b) << "\n";
    }

    /*for (int a = 2; a < 1000000; ++a) {
        int best = -1;
        vector<int> bs;
        for (int b = 1; b < a; ++b) {
            int tmp = gcd(a ^ b, a & b);
            if (tmp > best) {
                best = tmp;
                bs.clear();
            }
            if (tmp == best) {
                bs.push_back(b);
            }
        }
        //cout << a << ": " << best << endl;
        //for (int x : bs) cout << x << " ";
        //cout << endl << endl;


        int b = 0;
        for (int i = 0; i < 25; ++i) {
            if (!(a & (1 << i)) && (b | (1 << i)) < a) {
                b |= (1 << i);
            }
        }
        if (b == 0) {
            for (int d = 2; d * d <= a; ++d) {
                if (a % d == 0) {
                    b = a / d;
                    break;
                }
            }
            if (b == 0) {
                b = 1;
            }
        }
        if (b != bs[0]) {
            cout << "wrong: " << a << " " << b << " " << bs[0] << endl;
        }
    }*/
    return 0;
}