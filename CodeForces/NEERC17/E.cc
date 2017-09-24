#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

int main() {
  int n;
  string S;
  cin >> n >> S;
  vector<int> food, pacman;
  for (int i = 0; i < n; ++i) {
    if (S[i] == 'P') {
      pacman.push_back(i);
    } else if (S[i] == '*') {
      food.push_back(i);
    }
  }
  int low = 0, high = n * 2 + 10, ans = high;
  while (low <= high) {
    int mid = (low + high) / 2;
    int ind = 0;
    for (int p : pacman) {
      int from = p, to = p;
      while (ind < (int)food.size()) {
        from = min(from, food[ind]);
        to = max(to, food[ind]);
        int needed = to - from + min(to - p, p - from);
        if (needed > mid) {
          break;
        }
        ++ind;
      }
    }
    if (ind == (int)food.size()) {
      high = mid - 1;
      ans = mid;
    } else {
      low = mid + 1;
    }
  }
  cout << ans << "\n";
  return 0;
}
