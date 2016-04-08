#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N, newline = 0;
	while(cin >> N && !cin.eof() && ++newline)
	{
		if(newline > 1)
			cout << endl;

		vector<string> names(N);
		for(int n = 0; n < N; ++n)
			cin >> names[n];

		vector<int> value(N), given(N);
		string cur;
		int amount, I, k, j;
		for(int n = 0; n < N; ++n)
		{
			cin >> cur >> amount >> I;

			for(k = 0; k < N; ++k)
				if(names[k] == cur)
					break;

			for(int i = 0; i < I; ++i)
			{
				cin >> cur;
				for(j = 0; j < N; ++j)
					if(names[j] == cur)
						break;

				value[j] += amount / I;
				given[k] -= amount / I;
			}
		}
		for(int n = 0; n < N; ++n)
			cout << names[n] << " " << given[n] + value[n] << endl;
	}
	return 0;
}