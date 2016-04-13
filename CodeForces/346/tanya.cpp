#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 1e9+1
int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> v(N);
	for(int i = 0; i < N; ++i)
		cin >> v[i];
	v.push_back(INF);

	sort(v.begin(), v.end());

	int i = 1, sum = 0, j = 0, cnt = 0;
	vector<int> t;

	for(int j = 0; j <= N; ++j)
	{
		while(sum+i <= M && i < v[j])
		{
			t.push_back(i);
			sum += i;
			++i, ++cnt;
		}
		++i;
	}

	cout << cnt << endl;
	for(int toy: t)
		cout << toy << " ";

	return 0;
}