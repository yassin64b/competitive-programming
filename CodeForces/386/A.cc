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

    int a, b, c;
    cin >> a >> b >> c;

    int x = min(a, min(b/2, c/4));
    cout << x + x*2 + x*4 << endl;

    return 0;
}