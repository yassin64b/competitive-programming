#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    int x = 0, y = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == 'N') {
            --y;
        } else if (s[i] == 'S') {
            ++y;
        } else if (s[i] == 'E') {
            --x;
        } else {
            ++x;
        }
    }
    cout << abs(x) + abs(y) << "\n";
    
    return 0;
}