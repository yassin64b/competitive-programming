#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> t(n);
  for (int i = 0; i < n; ++i) {
    cin >> t[i];
  }

  int diff = t[1] - t[0];
  if (n == 2) {
    cout << t[1] + diff << "\n";
    return 0;
  }
  bool isArithProg = true;
  for (int i = 2; i < n; ++i) {
    if (t[i] != t[i - 1] + diff) {
      isArithProg = false;
    }
  }
  if (isArithProg) {
    cout << t[n - 1] + diff << "\n";
  } else {
    cout << t[n - 1] << "\n";
  }
}
