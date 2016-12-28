#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>

using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	long long left = 1, right = 1;
	for(int i = 0; i < N; ++i)
	{
		long long ll = left, lr = right;
		int T, A;
		long long t, a;
		cin >> T >> A;
		long long mult = max(left/T, right/A);
		t = (mult)*T, a = (mult)*A;
		while(t < left || a < right)
		{
			t += T, a += A;
		}
		left = t, right = a;

		
		//cout << left << " " << right << endl;
	}
	cout << left + right << endl;

	return 0;
}