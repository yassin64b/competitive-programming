#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <set>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
 
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int oddcnt = 0, evcnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            ++evcnt;
        } else {
            ++oddcnt;
        }
    }

    int mnres = max(oddcnt, evcnt) - n/2;
    if (mnres > m) {
        cout << -1 << endl;
        return 0;
    }

    set<int> seen;
    set<pair<int, int>> sodd, sev;
    set<pair<int, int>> coll;
    for (int i = 0; i < n; ++i) {
        if (seen.find(a[i]) != seen.end()) {
            coll.insert({a[i], i});
            if (a[i] % 2 == 0) {
                sev.insert({a[i], i});
            } else {
                sodd.insert({a[i], i});
            }
        } else {
            seen.insert(a[i]);
        }
    }

    int res = 0;
    int freevalodd = 1, freevalev = 2;
    for (auto &p : coll) {
        if (p.first % 2 == 0) {
            if (evcnt > oddcnt) {
                ++res;
                while(seen.find(freevalodd) != seen.end()) {
                    freevalodd += 2;
                }
                //cout << p.second << " : " << freevalodd << endl;
                a[p.second] = freevalodd;
                if (freevalodd > m) {
                    cout << -1 << endl;
                    return 0;
                }
                freevalodd += 2;
                ++oddcnt; --evcnt;
            } else {
                ++res;
                while(seen.find(freevalev) != seen.end()) {
                    freevalev += 2;
                }
                //cout << p.second << " : " << freevalev << endl;
                a[p.second] = freevalev;
                if (freevalev > m) {
                    cout << -1 << endl;
                    return 0;
                }
                freevalev += 2;
            }
        } else {
            if (evcnt < oddcnt) {
                ++res;
                while(seen.find(freevalev) != seen.end()) {
                    freevalev += 2;
                }
                //cout << p.second << " : " << freevalev << endl;
                a[p.second] = freevalev;
                if (freevalev > m) {
                    cout << -1 << endl;
                    return 0;
                }
                freevalev += 2;
                ++evcnt; --oddcnt;
            } else {
                ++res;
                while(seen.find(freevalodd) != seen.end()) {
                    freevalodd += 2;
                }
                //cout << p.second << " : " << freevalodd << endl;
                a[p.second] = freevalodd;
                if (freevalodd > m) {
                    cout << -1 << endl;
                    return 0;
                }
                freevalodd += 2;
            }
        }
    }

    int i = 0;
    while (evcnt < oddcnt) {
        while (a[i] % 2 == 0) ++i;

        ++res;
        while(seen.find(freevalev) != seen.end()) {
            freevalev += 2;
        }
        a[i] = freevalev;
        if (freevalev > m) {
            cout << -1 << endl;
            return 0;
        }
        freevalev += 2;
        ++evcnt; --oddcnt;
    }
    while (evcnt > oddcnt) {
        while (a[i] % 2 == 1) ++i;
        
        ++res;
        while(seen.find(freevalodd) != seen.end()) {
            freevalodd += 2;
        }
        a[i] = freevalodd;
        if (freevalodd > m) {
            cout << -1 << endl;
            return 0;
        }
        freevalodd += 2;
        ++oddcnt; --evcnt;

    }


    cout << res << endl;
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }


    return 0;
}