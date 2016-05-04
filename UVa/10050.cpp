#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for(int t = 1; t <= T; ++t)
	{
		int N, P, cnt = 0;
		cin >> N >> P;

		vector<int> h(P);

		for(int i = 0; i < P; ++i)
			cin >> h[i];

		for(int i = 1; i <= N; ++i)
		{
			if(i % 7 == 6 || i % 7 == 0) continue;

			for(int j = 0; j < P; ++j)
				if(i % h[j] == 0) 
				{
					++cnt;
					break;
				}
		}

		cout << cnt << endl;
	}

	return 0;		
}