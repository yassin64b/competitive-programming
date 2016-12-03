#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    map<int, int> langs;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        langs[a[i]]++;
    }

    int m;
    cin >> m;

    vector<int> b(m), c(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i];
    }

    pair<int, int> opt{0, 0};
    int ind = 1;
    for (int i = 0; i < m; ++i) {
        if (langs.find(b[i]) != langs.end() && langs[b[i]] > opt.first) {
            opt = {langs[b[i]], langs[c[i]]};
            ind = i+1;
        } else if (((langs.find(b[i]) == langs.end() && opt.first == 0) 
                    || langs[b[i]] == opt.first) && langs[c[i]] > opt.second) {
            opt.second = langs[c[i]];
            ind = i+1;
        }
    }
    cout << ind << endl;
    return 0;
}