#include <bits/stdc++.h>

using namespace std;

int getx(int s) {
    --s;
    return s / 3;
}

int gety(int s) {
    --s;
    return s % 3;
}

int gets(int x, int y, int g[3][3]) {
    g[x][y] = 1;
    return 3 * x + y + 1;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    

    int g[3][3]{0};
    cout << 5 << endl;
    g[1][1] = 1;

    for (int j = 0; j < 4; ++j) {
        int s;
        cin >> s;
        if (s == -1) {
            return 0;
        }
        int x = getx(s), y = gety(s);
        g[x][y] = 2;

        for (int i = 0; i < 3; ++i) {
            int cnt1 = (g[i][0] == 1) + (g[i][1] == 1) + (g[i][2] == 1);
            int cnt2 = (g[i][0] == 2) + (g[i][1] == 2) + (g[i][2] == 2);
            if (cnt1 == 2 && cnt2 == 0) {
                if (g[i][0] == 0) {
                    cout << gets(i, 0, g) << endl;
                } else if (g[i][1] == 0) {
                    cout << gets(i, 1, g) << endl;
                } else {
                    cout << gets(i, 2, g) << endl;
                }
                return 0;
            }
        }
        for (int i = 0; i < 3; ++i) {
            int cnt1 = (g[0][i] == 1) + (g[1][i] == 1) + (g[2][i] == 1);
            int cnt2 = (g[0][i] == 2) + (g[1][i] == 2) + (g[2][i] == 2);
            if (cnt1 == 2 && cnt2 == 0) {
                if (g[0][i] == 0) {
                    cout << gets(0, i, g) << endl;
                } else if (g[1][i] == 0) {
                    cout << gets(1, i, g) << endl;
                } else {
                    cout << gets(2, i, g) << endl;
                }
                return 0;
            }
        }

        for (int i = 0; i < 3; ++i) {
            int cnt1 = (g[i][0] == 1) + (g[i][1] == 1) + (g[i][2] == 1);
            int cnt2 = (g[i][0] == 2) + (g[i][1] == 2) + (g[i][2] == 2);
            if (cnt1 == 0 && cnt2 == 2) {
                if (g[i][0] == 0) {
                    cout << gets(i, 0, g) << endl;
                } else if (g[i][1] == 0) {
                    cout << gets(i, 1, g) << endl;
                } else {
                    cout << gets(i, 2, g) << endl;
                }
                goto nxt_it;
            }
        }
        for (int i = 0; i < 3; ++i) {
            int cnt1 = (g[0][i] == 1) + (g[1][i] == 1) + (g[2][i] == 1);
            int cnt2 = (g[0][i] == 2) + (g[1][i] == 2) + (g[2][i] == 2);
            if (cnt1 == 0 && cnt2 == 2) {
                if (g[0][i] == 0) {
                    cout << gets(0, i, g) << endl;
                } else if (g[1][i] == 0) {
                    cout << gets(1, i, g) << endl;
                } else {
                    cout << gets(2, i, g) << endl;
                }
                goto nxt_it;
            }
        }

        for (int i = 0; i < 3; ++i) {
            int cnt1 = (g[i][0] == 1) + (g[i][1] == 1) + (g[i][2] == 1);
            int cnt2 = (g[i][0] == 2) + (g[i][1] == 2) + (g[i][2] == 2);
            if (cnt1 == 0 && cnt2 == 1) {
                if (g[i][0] == 0) {
                    cout << gets(i, 0, g) << endl;
                } else if (g[i][1] == 0) {
                    cout << gets(i, 1, g) << endl;
                } else {
                    cout << gets(i, 2, g) << endl;
                }
                goto nxt_it;
            }
        }
        for (int i = 0; i < 3; ++i) {
            int cnt1 = (g[0][i] == 1) + (g[1][i] == 1) + (g[2][i] == 1);
            int cnt2 = (g[0][i] == 2) + (g[1][i] == 2) + (g[2][i] == 2);
            if (cnt1 == 0 && cnt2 == 1) {
                if (g[0][i] == 0) {
                    cout << gets(0, i, g) << endl;
                } else if (g[1][i] == 0) {
                    cout << gets(1, i, g) << endl;
                } else {
                    cout << gets(2, i, g) << endl;
                }
                goto nxt_it;
            }
        }

        for (int i = 0; i < 3; ++i) {
            int cnt1 = (g[i][0] == 1) + (g[i][1] == 1) + (g[i][2] == 1);
            int cnt2 = (g[i][0] == 2) + (g[i][1] == 2) + (g[i][2] == 2);
            if (cnt1 + cnt2 != 3) {
                if (g[i][0] == 0) {
                    cout << gets(i, 0, g) << endl;
                } else if (g[i][1] == 0) {
                    cout << gets(i, 1, g) << endl;
                } else {
                    cout << gets(i, 2, g) << endl;
                }
                goto nxt_it;
            }
        }

        nxt_it:;
    }

    return 0;
}