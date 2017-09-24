#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  vector<int> v(7, 0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 7; ++j) {
      char c;
      cin >> c;
      if (c == '1') {
        ++v[j];
      }
    }
  }
  std::cout << *max_element(v.begin(), v.end()) << "\n";
  return 0;
}
