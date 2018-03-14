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
    string res;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (i > 0 && s[i] == 'A' && s[i - 1] == 'A') {
            
        } else {
            res += s[i];
        }
    }
    cout << res << endl;
    
    return 0;
}