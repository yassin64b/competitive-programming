#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> win_cnt(N, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int x;
            cin >> x;
            if (x == 1) {
                ++win_cnt[i];
            } else if (x == 2) {
                ++win_cnt[j];
            }
        }
    }

    cout << max_element(win_cnt.begin(), win_cnt.end()) - win_cnt.begin() + 1 << "\n";
    
    return 0;
}