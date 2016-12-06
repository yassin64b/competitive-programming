#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main()
{
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> crush(n);
    for (int i = 0; i < n; ++i) {
        cin >> crush[i];
        --crush[i];
    }

    vector<int> a, vis(n, 0);
    for (int i = 0; i < n; ++i) {
        int j = i, cnt = 1;
        vis.assign(n, 0);
        while (crush[j] != i) {
            ++cnt;
            if (vis[j] == true) {
                cout << -1 << endl;
                return 0;
            }
            vis[j] = true;
            j = crush[j];
        }
        //cout << cnt << endl;
        if (cnt % 2 == 0)
            a.push_back(cnt/2);
        else 
            a.push_back(cnt);
    }

    int res = 1;
    for (size_t i = 0; i < a.size(); ++i) {
        res = lcm(res, a[i]);
    }

    cout << res << endl;

    return 0;
}