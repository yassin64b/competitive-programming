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

    int n, k, w;
    cin >> n >> k >> w;

    string candy;
    cin >> candy;

    vector<int> ccnt(n+1), cmcnt(n+1);
    ccnt[0] = cmcnt[0] = 0;

    for (int i = 1; i <= n; ++i) {
        ccnt[i] = ccnt[i-1] + (candy[i-1] - '0');
    }

    for (int i = 0; i < k; ++i) {
        cmcnt[i] = 0;
    }
    for (int i = k; i <= n; ++i) {
        cmcnt[i] = cmcnt[i-k] + (candy[i-1] - '0');
    }

    for (int i = 0; i < w; ++i) {
        int l, r;
        cin >> l >> r;
        int are = cmcnt[r] - cmcnt[l-1];
        int add = (r - l + 1) / k - are;
        int rem = ccnt[r] - ccnt[l-1] - are;

        cout << add + rem << endl;
    }

    return 0;
}