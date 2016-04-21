#include <cstdio>
#include <vector>
using namespace std;

bool coprime(int a, int b)
{
	if(a < b)
		return coprime(b, a);
	else
	{
		if(a%b == 0)
			return (b == 1);
		else
			return coprime(b, a%b);
	}
}

int main()
{
	int N;
	scanf("%d", &N);

	vector<int> a(N);

	for(int n = 0; n < N; ++n)
		scanf("%d", &a[n]);

	vector<int> v;

	v.push_back(a[0]);
	for(int n = 1; n < N; ++n)
	{
		if(!coprime(a[n-1], a[n]))
			v.push_back(1);

		v.push_back(a[n]);
	}

	printf("%d\n", (int)v.size() - N);

	printf("%d", v[0]);
	for(int i = 1; i < (int)v.size(); ++i)
		printf(" %d", v[i]);
}