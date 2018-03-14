#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    vector<int> num(100'000 + 1, 0);
    for (int i = 0; i <= 100'000; ++i) {
        for (int j = 5; i / j >= 1; j *= 5)
          num[i] += i / j;
    }
    int low = 0, high = 1'000'000, ans = low;
    while (low <= high) {
        int mid = (low + high) / 2;
        cout << "Q " << mid << "\n";
        cout.flush();
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            low = mid + 1;
            ans = mid;
        } else {
            assert(tmp == 0);
            high = mid - 1;
        }
    }
    for (int i = 0; i <= 100'000; ++i) {
        if (num[i] == ans) {
            cout << "A " << i << "\n";
            return 0;
        }
    }
    
    return 0;
}