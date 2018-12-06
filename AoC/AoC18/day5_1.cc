#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    string s;
    cin >> s;

    list<char> l(begin(s), end(s));
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

    for (char c : l) {
        cout << c;
    }
    cout << endl;
    cout << l.size() << endl;
    
    return 0;
}
