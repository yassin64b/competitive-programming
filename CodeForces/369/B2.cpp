#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  
  int n, indi, indj;
  cin >> n;
  
  vector<vector<int64_t>> grid(n, vector<int64_t>(n));
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

  int64_t sum = 0;
  int ind = (indi == 0 ? 1 : 0);
  for (int i = 0; i < n; ++i) {
	sum += grid[ind][i];
  }
  int64_t x = sum;
  for (int i = 0; i < n; ++i) {
	x -= grid[indi][i];
  }
  if (x < 1) {
	cout << -1 << endl;
	return 0;
  }
  grid[indi][indj] = x;
  
  int64_t diagsum = 0, secdsum = 0;
  for (int i = 0; i < n; ++i) {
	diagsum += grid[i][i];
	secdsum += grid[i][n-i-1];
  }
  if (diagsum != sum || secdsum != sum) {
	cout << -1 << endl;
	return 0;
  }

  for (int i = 0; i < n; ++i) {
	int64_t rowsum = 0, colsum = 0;
	for (int j = 0; j < n; ++j) {
	  rowsum += grid[i][j];
	  colsum += grid[j][i];
	}
	if (rowsum != sum || colsum != sum) {
	  cout << -1 << endl;
	  return 0;
	}
  }
  cout << x << endl;

  return 0;
}
