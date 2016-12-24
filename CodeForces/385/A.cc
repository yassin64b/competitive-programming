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

    string s;
    cin >> s;

    map<string, int> m;
    int cnt = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        string t = s.substr(s.size()-i, i) + s.substr(0, s.size()-i);
        //cout << t << endl;
        if (m[t] == 0) {
            ++cnt;
        }
        ++m[t];
    }

    cout << cnt << endl;

    return 0;
}

