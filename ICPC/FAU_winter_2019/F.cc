#include <bits/stdc++.h>

using namespace std;

void db(int t, int p, int k, int n, vector<int> &a, vector<int> &seq) {
    if (t > n) {
        if (n % p == 0) {
            for (int i = 1; i <= p; ++i) {
                seq.push_back(a[i]);
            }
        }
    } else {
        a[t] = a[t - p];
        db(t + 1, p, k, n, a, seq);
        for (int j = a[t - p] + 1; j < k; ++j) {
            a[t] = j;
            db(t + 1, t, k, n, a, seq);
        }
    }
}

vector<int> de_bruijn(int k, int n) {
    vector<int> a(k * n, 0), seq;
    db(1, 1, k, n, a, seq);
    return seq;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    constexpr int MX = 10'000;


    vector<int> iseq = de_bruijn(26, 4);
    iseq.push_back(iseq[0]);
    iseq.push_back(iseq[1]);
    iseq.push_back(iseq[2]);
    iseq.push_back(iseq[3]);

    const int m = iseq.size();
    string seq(m, 'a');
    for (int i = 0; i < m; ++i) {
        seq[i] += iseq[i];
    }
    string cur;
    for (int i = 0; i < m; i += 9'990) {
        cur = seq.substr(max(0, i - 4), 9'990 + 4);
        cout << "? " << cur << "\n";
        cout.flush();
        string ans;
        cin >> ans;
        if (ans == "yes") {
            goto start;
        }
    }


start:;
    int n = cur.size();
    int low = 0, high = n - 1;
    for (int it = 0; it < 50; ++it) {
        int len = (high - low + 1);
        int mid = low + len / 2;

        string ask = cur.substr(low, max(4, len / 2));
        cout << "? " << ask << "\n";
        cout.flush();
        string ans;
        cin >> ans;

        if (ans == "yes" && ask.size() == 4U) {
            cout << "! " << ask << "\n";
            cout.flush();
            return 0;
        } else if (ans == "yes") {
            high = max(mid, low + 3);
        } else {
            int end = low + max(4, len / 2);
            low = min(high - 3, end - 3);
        }
    }

    return 0;
}