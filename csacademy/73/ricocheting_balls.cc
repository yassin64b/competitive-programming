#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    int low = 0, high = 1'000'000'000, ans = low;
    while (low <= high) {
        int mid = (low + high) / 2;
        long long sum1 = 0, sum2 = 0;
        for (int x : h) {
            sum1 += abs(x - mid);
            sum2 += abs(x - (mid + 1));
        }
        if (sum2 <= sum1) {
            low = mid + 1;
            ans = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    long long res = 0;
    for (int x : h) {
        res += abs(x - ans);
    }
    cout << res << endl;
    return 0;
}