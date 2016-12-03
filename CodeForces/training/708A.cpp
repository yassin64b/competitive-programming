#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] != 'a') {
            while (i < (int)s.size() && s[i] != 'a') {
                --s[i++];
            }
            cout << s << endl;
            return 0;
        }
    }
    s[s.size()-1] = 'z';
    cout << s << endl;

    return 0;
}