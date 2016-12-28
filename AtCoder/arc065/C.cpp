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

    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == 'd') {
            if (i + 4 >= s.size() || s[i+1] != 'r' || s[i+2] != 'e' || s[i+3] != 'a'
                || s[i+4] != 'm') {
                cout << "NO" << endl;
                return 0;
            } 
            i += 4;
            if (i + 2 <= s.size()) {
                if (s[i+1] == 'e' && s[i+2] == 'r') {
                    if (i + 3 < s.size() && s[i+3] == 'a') {
                        continue;
                    } else {
                        i += 2;
                    }
                }
            } 
        } else if (s[i] == 'e') {
            if (i + 3 >= s.size() || s[i+1] != 'r' || s[i+2] != 'a' || s[i+3] != 's' 
                || s[i+4] != 'e') {
                cout << "NO" << endl;
                return 0;
            }
            i += 4;
            if (i + 1 < s.size() && s[i+1] == 'r') {
                ++i;
            }
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;

    return 0;
}