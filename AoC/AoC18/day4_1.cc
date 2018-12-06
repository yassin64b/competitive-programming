#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    vector<tuple<int, int, int, int, int, int>> v;
    while (getline(cin, s)) {
        stringstream ss(s);
        char t;
        int y, m, d, hh, mm;
        ss >> t >> y >> t >> m >> t >> d;
        ss >> hh >> t >> mm >> t;
        string nxt;
        ss >> nxt;
        if (nxt == "Guard") {
            int id;
            ss >> t >> id;
            assert(id >= 0);
            v.emplace_back(y, m, d, hh, mm, id);
        } else if (nxt == "falls") {
            v.emplace_back(y, m, d, hh, mm, -1);
        } else {
            assert(nxt == "wakes");
            v.emplace_back(y, m, d, hh, mm, -2);
        }
    }

    sort(begin(v), end(v));
    map<int, int> cnt;
    int cur = -1, start_t = 0;
    for (auto [y, m, d, hh, mm, id] : v) {
        //cout << y << " " << m << " " << d << " " << hh << " " << mm << " " << id << endl;
        if (id >= 0) {
            cur = id;
        } else if (id == -1) {
            start_t = mm;
        } else {
            cnt[cur] += mm - start_t;
        }
    }
    int mx = -1, mx_id = -1;
    for (auto [k, v] : cnt) {
        if (v > mx) {
            mx = v;
            mx_id = k;
        }
    }
    vector<int> mm_cnt(60, 0);
    for (auto [y, m, d, hh, mm, id] : v) {
        //cout << y << " " << m << " " << d << " " << hh << " " << mm << " " << id << endl;
        if (id >= 0) {
            cur = id;
        } else if (cur == mx_id) {
            if (id == -1) {
                mm_cnt[mm] += 1;
            } else {
                mm_cnt[mm] -= 1;
            }
        }
    }
    int mm_mx = mm_cnt[0], mm_id = 0;
    for (int i = 1; i < 60; ++i) {
        mm_cnt[i] += mm_cnt[i - 1];
        if (mm_cnt[i] > mm_mx) {
            mm_cnt[i] = mm_mx;
            mm_id = i;
        }
    }
    cout << mx_id * mm_id << endl;
    
    return 0;
}
