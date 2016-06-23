#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> v(N);
	for(int i = 0; i < N; ++i)
		cin >> v[i];
	
	for(int i = 1; i < N; ++i)
	{
		for(int j = 0; j < N-1; ++j)
		{
			if(v[j] > v[j+1]) 
			{
				cout << j+1 << ' ' << j+2 << endl;

				int tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
			/*for(int i = 0; i < N; ++i)
				cout << v[i] << ' ';
			cout << endl;*/
		}
	}
}
