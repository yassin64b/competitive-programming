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

    int n, a, b;
    cin >> n >> a >> b;

    string s;
    cin >> s;

    if (s[a-1] == s[b-1]) {
        cout << 0 << endl;
    } else {
        cout << 1 << endl;
    }


    return 0;
}