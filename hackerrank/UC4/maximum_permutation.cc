#include <cassert>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 1 << 21;
string S;
int N, gap;
int sa[MAXN], pos[MAXN], tmp[MAXN], lcp[MAXN];

bool sufCmp(int i, int j)
{
    if (pos[i] != pos[j])
        return pos[i] < pos[j];
    i += gap;
    j += gap;
    return (i < N && j < N) ? pos[i] < pos[j] : i > j;
}

void buildSA()
{
    N = S.size();
    for (int i = 0; i < N; ++i) sa[i] = i, pos[i] = S[i];
    for (gap = 1;; gap *= 2)
    {
        sort(sa, sa + N, sufCmp);
        for (int i = 0; i < N - 1; ++i) tmp[i + 1] = tmp[i] + sufCmp(sa[i], sa[i + 1]);
        for (int i = 0; i < N; ++i) pos[sa[i]] = tmp[i];
        if (tmp[N - 1] == N - 1) break;
    }
}

void buildLCP()
{
    for (int i = 0, k = 0; i < N; ++i) if (pos[i] != N - 1)
    {
        for (int j = sa[pos[i] + 1]; i + k < N && j + k < N && S[i + k] == S[j + k];)
            ++k;
        lcp[pos[i]] = k;
        if (k)--k;
    }
}

bool equal(const int *a, const int *b) {
    for (int i = 0; i < 26; ++i) if (a[i] != b[i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        string w, s;
        cin >> w >> s;
        int n = w.size(), m = s.size();
        S = s;
        for (int i = 0; i < MAXN; ++i) sa[i] = pos[i] = tmp[i] = lcp[i] = 0;
        buildSA();
        buildLCP();
        vector<bool> ok(N, false);
        int cnt1[26]{}, cnt2[26]{};
        for (char c : w) ++cnt1[c - 'a'];
        for (int i = 0; i < n; ++i) ++cnt2[s[i] - 'a'];
        if (equal(cnt1, cnt2)) ok[0] = true;
        for (int i = n; i < m; ++i) {
            --cnt2[s[i - n] - 'a']; ++cnt2[s[i] - 'a'];
            if (equal(cnt1, cnt2)) ok[i - n + 1] = true;
        }
        int mx = 0, ind = -1;
        for (int i = 0; i < N; ) {
            if (ok[sa[i]]) {
                int j = i;
                while (j < N && lcp[j] >= n) {
                    ++j;
                    //assert(ok[sa[j]]);
                }
                if (j - i + 1 > mx) {
                    mx = j - i + 1;
                    ind = sa[i];
                }
                i = j + 1;
            } else ++i;
        }
        //cout << ind << endl;
        if (ind == -1) {
            cout << -1 << "\n";
        } else {
            cout << s.substr(ind, n) << "\n";
        }
        
    }
    return 0;
}