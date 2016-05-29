#include <cstdio>
#include <cstring>

int main()
{
	int N;
	scanf("%d", &N);

	int T[5001];
	for(int i = 1; i <= N; ++i)
		scanf("%d", &T[i]);

	int dominant = 0;
	int cnt[5001] = {0}, res[5001] = {0};
	for(int i = 1; i <= N; ++i)
	{
		memset(cnt, 0, sizeof(cnt));
		for(int j = i; j <= N; ++j)
		{
			if(++cnt[T[j]] > cnt[dominant] || (cnt[T[j]] == cnt[dominant] && T[j] < dominant))
				dominant = T[j];
			//cout << i << "," << j << ": " << dominant << endl;
			++res[dominant];
		}
	}

	for(int i = 1; i <= N; ++i)
		printf("%d ", res[i]);

	return 0;
}