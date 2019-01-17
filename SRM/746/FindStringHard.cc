#include <bits/stdc++.h>

using namespace std;

class FindStringHard {
public:
    string withAntipalindromicSubstrings(int);
};

string FindStringHard::withAntipalindromicSubstrings(int n) {
    string res;
    while (n) {
        int len = 0;
        for (int i = 0, turn = 0; ; ++i, turn = 1 - turn) {
            int nxtlen = len + 1;
            int nxtn = (nxtlen / 2) * ((nxtlen + 1) / 2);
            if (nxtn <= n) {
                len = nxtlen;
                res += (turn ? "b" : "a");
            } else {
                break;
            }
        }
        if (res.back() == 'b' && n != ((len / 2) * ((len + 1) / 2))) {
            res.pop_back();
            --len;
        }
        n -= (len / 2) * ((len + 1) / 2);
    }
    return res;
}