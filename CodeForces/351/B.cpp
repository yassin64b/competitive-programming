#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	int a = 1, b = N;

	for(int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;

		a = max(a, min(u, v));
		b = min(b, max(u, v));
		//cout << a << "-" << b << endl;
	}
	cout << max(0, b-a) << endl;
}