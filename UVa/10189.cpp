#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 104
int main()
{
	int N, M, cnt, m[SIZE][SIZE], t = 0;
	char c;

	while(cin >> N >> M && (N || M) && ++t)
	{
		if(t > 1) cout << '\n';
		
		memset(m,0x00,SIZE*SIZE*sizeof(int));

		for(int i = 1; i <= N; ++i)
			for(int j = 1; j <= M; ++j)
			{
				cin >> c;
				if(c == '*')
					m[i][j] = 1;
			}	

		cout << "Field #" << t << ":\n";
		for(int i = 1; i <= N; ++i)
		{
			for(int j = 1; j <= M; ++j)
			{
				cnt = m[i-1][j-1] + m[i-1][j] + m[i-1][j+1]
							+ m[i][j-1] + m[i][j]
							+ m[i][j+1] + m[i+1][j-1] 
							+ m[i+1][j] + m[i+1][j+1];

				if(m[i][j] == 1)
					cout << '*';
				else
					cout << cnt;
			}
			cout << '\n';
		}

	}
}