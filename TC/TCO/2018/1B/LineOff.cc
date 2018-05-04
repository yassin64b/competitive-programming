#include <bits/stdc++.h>

using namespace std;

class LineOff {
public:
    int movesToDo(string);
};

int LineOff::movesToDo(string s) {
    int n = s.size();
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == s[i + 1]) {
            return 1 + movesToDo(s.substr(0, i) + s.substr(i + 2));
        }
    }
    return 0;
}