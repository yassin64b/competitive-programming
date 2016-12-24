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

    int n;
    string s;
    cin >> n >> s;

    string res;
    if (n % 2 == 1) {
        res = s[0];
        s.erase(s.begin());
    }

    for (size_t i = 0; i < s.size(); i += 2) {
        res = s[i] + res + s[i+1];
    } 

    cout << res << endl;

    return 0;
}