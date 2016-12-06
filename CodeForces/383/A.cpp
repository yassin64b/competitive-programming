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
    cin >> n;

    int res;
    if (n == 0) {
        res = 1;
    } else if (n % 4 == 0) {
        res = 6;
    } else if (n % 4 == 1) {
        res = 8;
    } else if (n % 4 == 2) {
        res = 4;
    } else {
        res = 2;
    }

    cout << res << endl;    

    return 0;
}