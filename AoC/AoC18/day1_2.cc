#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);

    int num;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    int cur = 0, ind = 0;
    set<int> seen;
    while (!seen.count(cur)) {
        seen.insert(cur);
        if (ind == (int)nums.size()) {
            ind = 0;
        }
        cur += nums[ind++];
    }
    cout << cur << endl;

    return 0;
}
