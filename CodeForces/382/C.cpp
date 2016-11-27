#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int64_t n;
  cin >> n;

  if (n == 2) {
    cout << 1 << endl;
    return 0;
  }

  int64_t fib1 = 1, fib2 = 1;
  int64_t sum = fib1 + fib2;
  int cnt = 2;
  while (sum < n) {
    int64_t tmp = fib2;
    fib2 += fib1;
    fib1 = tmp;
    sum += fib2;
    ++cnt;
  }

  cout << cnt-1 << endl;

  return 0;
}