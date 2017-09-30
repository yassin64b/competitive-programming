#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int N;
	cin >> N;
	cout << (1 << N) - N - 1 << "\n";

	return 0;
}