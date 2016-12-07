#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int64_t n, n2;
  cin >> n;
  n2 = n * n;

  if (n <= 2) {
    cout << - 1 << endl;
  } else if (n % 2 == 0) {
    cout << (n2 / 4 - 1) << " ";
    cout << (n2 / 4 + 1) << endl;
  } else {
    cout << ((n2 - 1) / 2) << " ";
    cout << ((n2 + 1) / 2) << endl;
  }




  return 0;
}