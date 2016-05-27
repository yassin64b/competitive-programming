#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int N, t = 0, tmp;
	cin >> N;

	for(int i = 0; i < N; ++i)
	{
		cin >> tmp;
		if(tmp - t > 15)
			break;
		else
			t = tmp;
	}
	t = min(t + 15, 90);
	cout << t << endl;
}