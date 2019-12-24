#include <bits/stdc++.h>

using namespace std;

int query(string s) {
    //assert(!s.empty());
    //assert(s.size() <= 300U);
    cout << s << endl;
    int dist = 0;
    cin >> dist;
    if (dist <= 0) {
        exit(0);
    }
    return dist;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    string res;
    int x = query(string(300, 'a'));
    int y = query(string(300, 'b'));
    int num_a = 300 - x;
    int num_b = 300 - y;
    int len = num_a + num_b;

    if (num_a <= num_b) {
        res = string(len, 'a');
        int last_d = num_b;
        for (int i = 0; i < len; ++i) {
            res[i] = 'b';
            int d = query(res);
            if (d > last_d) {
                res[i] = 'a';
            } else {
                last_d = d;
            }
        }
    } else {
        res = string(len, 'b');
        int last_d = num_a;
        for (int i = 0; i < len; ++i) {
            res[i] = 'a';
            int d = query(res);
            if (d > last_d) {
                res[i] = 'b';
            } else {
                last_d = d;
            }
        }
    }
    
    query(res);

    return 0;
}