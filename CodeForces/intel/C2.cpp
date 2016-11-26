#include <cstdio>
#include <vector>
#include <cstdlib>
#include <utility>
using namespace std;

class Dsu
{
public:
	vector<int> p, rank;
	vector<long long> sum;

	Dsu(int n)
	{
		rank.assign(n, -1);
		sum.assign(n, 0);
		p.resize(n);
		for(int i = 0; i < n; ++i)
			p[i] = i;
	}
	void add(int a, int s)
	{
		rank[a] = 0;
		sum[a] = s;
	}
	int findSet(int a) 
	{ 
		return (p[a] == a ? a : (p[a] = findSet(p[a]))); 
	}
	void unionSets(int a, int b)
	{
		int x = findSet(a), y = findSet(b);
		if(x == y)
			return;
		if(rank[x] < rank[y])
			p[x] = y;
		else if(rank[x] > rank[y])
			p[y] = x;
		else
		{
			p[x] = y;
			++rank[y];
		}

	}
};

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> a(n), ord(n);
	vector<long long> res(n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i)
		scanf("%d", &ord[i]);

	Dsu dsu(n);
	long long maxsum = 0;
	res[n-1] = 0;
	for(int j = n-1; j > 0; --j)
	{
		int i = ord[j]-1;
		dsu.add(i, a[i]);
		if(i < n-1 && dsu.rank[i+1] != -1)
		{
			long long old = dsu.sum[dsu.findSet(i+1)], old1 = dsu.sum[dsu.findSet(i)];
			dsu.unionSets(i, i+1);
			dsu.sum[dsu.findSet(i)] = old + old1;
		}
		if(i > 0 && dsu.rank[i-1] != -1)
		{
			long long old = dsu.sum[dsu.findSet(i-1)], old1 = dsu.sum[dsu.findSet(i)];
			dsu.unionSets(i, i-1);
			dsu.sum[dsu.findSet(i)] = old + old1;
		}	
		maxsum = max(maxsum, dsu.sum[dsu.findSet(i)]);
		res[j-1] = maxsum;
	}
	for(int i = 0; i < n; ++i)
		printf("%lld\n", res[i]);

	return 0;
}