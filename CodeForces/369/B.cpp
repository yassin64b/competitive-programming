#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  
  int n, indi, indj;
  cin >> n;
  
  vector<vector<int>> grid(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
      if (grid[i][j] == 0) {
        indi = i;
        indj = j;
      }
    }
  }
  
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  int64_t rowsum = -1, colsum = -1, diagsum = 0, secdsum = 0;
  int64_t misrow = 0, miscol = 0;
  for (int i = 0; i < n; ++i) {
    int64_t tmprowsum = 0, tmpcolsum = 0;
    for (int j = 0; j < n; ++j) {
      if (i == indi) {
        misrow += grid[i][j];
      } else {
        tmprowsum += grid[i][j];
      }
      if (i == indj) {
        miscol += grid[j][i];
      } else {
        tmpcolsum += grid[j][i];
      }
    }
    //cout << tmprowsum << " " << tmpcolsum << endl;
    if (tmprowsum && rowsum != -1 && tmprowsum != rowsum) {
      cout << -1 << endl;
      return 0;
    } else if (tmpcolsum && colsum != -1 && tmpcolsum != colsum) {
      cout << -1 << endl;
      return 0;
    }
    if (tmprowsum) rowsum = tmprowsum;
    if (tmpcolsum) colsum = tmpcolsum;
  }

  for (int i = 0; i < n; ++i) {
    diagsum += grid[i][i];
    secdsum += grid[i][n-i-1];
  }
  
  //cout << rowsum << " " << colsum << " " << diagsum << " " << secdsum << endl;
  //cout << misrow << " " << miscol << " x: " << rowsum - misrow << endl;
  int64_t x = rowsum - misrow;
  if (x < 1 || colsum - miscol != x || (indi == indj && rowsum - diagsum != x) 
      || (indi != indj && rowsum != diagsum) || (indi != n - indj - 1 && rowsum != secdsum) 
      || (indi == n - indj - 1 && rowsum - secdsum != x)) {
    cout << -1 << endl;
  } else {
    cout << x << endl;
  }
 
  return 0;
}
