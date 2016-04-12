#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int gcd(int a, int b)
{
	if(b == 0) return a;
	return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return a*b/gcd(a,b);
}

int main()
{
	int N, M[16], R[16], limit, count = 0;
	cin >> N;

	for(int i = 0; i < N; ++i)
		cin >> M[i];
	for(int i = 0; i < N; ++i)
		cin >> R[i];

	limit = M[0];
	for(int i = 1; i < N; ++i)
		limit = lcm(limit, M[i]);

	for(int D = 0; D < limit; ++D)
	{
		for(int i = 0; i < N; ++i)
		{
			if(D % M[i] == R[i])
			{
				++count;
				break;
			}
		}
	}
	cout << fixed << setprecision(6);
	cout << count / (double) limit << endl;
}