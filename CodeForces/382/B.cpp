#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int n, n1, n2;
  cin >> n >> n1 >> n2;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end(), greater<int>());
  double m1 = 0, m2 = 0;
  if (n1 > n2)
    swap(n1, n2);
  for (int i = 0; i < n1; ++i) {
    m1 += a[i];
  }
  for (int i = 0; i < n2; ++i) {
    m2 += a[n1+i];
  }
  //cout << m1 << " " << m2 << endl;
  m1 /= n1;
  m2 /= n2;

  cout.precision(17);
  cout << fixed << m1 + m2 << endl;

  return 0;
}