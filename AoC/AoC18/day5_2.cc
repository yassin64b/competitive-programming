#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    cin >> s;
    
    list<char> orig_l(begin(s), end(s));
    int res = orig_l.size();
    for (char c = 'a'; c <= 'z'; ++c) {
        list<char> l(orig_l);
        for (auto it = begin(l); it != end(l); ) {
            if (tolower(*it) == c) {
                it = l.erase(it);
            } else {
                ++it;
            }
        }
        for (auto it = begin(l); it != end(l); ) {
            auto nxt = it;
            if (++nxt == end(l)) {
                break;
            }
            if (tolower(*it) == tolower(*nxt) && *it != *nxt) {
                auto new_it = it;   
                if (new_it == begin(l)) {
                    new_it = nxt;
                    ++new_it;
                } else {
                    --new_it;
                }
                l.erase(it);
                l.erase(nxt);
                it = new_it;
            } else {
                ++it;
            }
        }

        res = min(res, (int)l.size());
    }
    
    cout << res << endl;
    
    return 0;
}
