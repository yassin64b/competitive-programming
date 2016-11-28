#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n-1; ++i) {
    cout << a[i] + a[i+1] << " ";
  }
  cout << a[n-1] << endl;

  return 0;
}