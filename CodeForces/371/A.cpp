#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	long long l1, r1, l2, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;

	long long res = min(r1, r2) - max(l1, l2) + 1;
	if(k <= min(r1, r2) && k >= max(l1, l2))
		--res;
	
	cout << (res < 0 ? 0 : res) << endl; 
	return 0;
}