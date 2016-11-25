#include <iostream>
#include <string>
#include <regex>

using namespace std;

int main() 
{
    int n;
    string s;
    cin >> n >> s;

    regex e ("ogo(go)*");
    string res = regex_replace(s, e, "***");

    cout << res << endl;
    return 0;
}