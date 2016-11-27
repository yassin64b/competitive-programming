#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

bool isPrime(int64_t n)
{
  for (int64_t i = 2; i*i <= n; ++i) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main()
{
  ios::sync_with_stdio(false);

  int64_t n;
  cin >> n;

  if (isPrime(n)) {
    cout << 1 << endl;
  } else if (n % 2 == 0) {
    cout << 2 << endl;
  } else if (n > 4 && isPrime(n-2)) {
    cout << 2 << endl;
  } else {
    cout << 3 << endl;
  }


  return 0;
}