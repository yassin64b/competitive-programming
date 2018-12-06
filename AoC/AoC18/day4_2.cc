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
    
    int cur = -1;
    map<int, vector<int>> mm_cnt;
    for (auto [y, m, d, hh, mm, id] : v) {
        //cout << y << " " << m << " " << d << " " << hh << " " << mm << " " << id << endl;
        if (id >= 0) {
            cur = id;
            if (!mm_cnt.count(cur)) {
                mm_cnt[cur] = vector<int>(60, 0);
            }
        } else if (id == -1) {
            mm_cnt[cur][mm] += 1;
        } else {
            mm_cnt[cur][mm] -= 1;
        }
    }
    int mm_mx = -1, guard_id = -1, mm_id = -1;
    for (auto [k, v] : mm_cnt) {
        for (int i = 0; i < 60; ++i) {
            if (i > 0) {
                v[i] += v[i - 1];
            }
            if (v[i] > mm_mx) {
                mm_mx = v[i];
                mm_id = i;
                guard_id = k;
            }
        }
    }
    cout << guard_id << " " << mm_id << " " << mm_mx << endl;
    cout << guard_id * mm_id << endl;
    
    return 0;
}
