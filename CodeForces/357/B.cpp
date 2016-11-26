#include <iostream>
#include <string>
using namespace std;

#define HOUSE 1234567
#define CAR 123456
#define COMP 1234

int main()
{
	int N;
	cin >> N;

	bool flag = false;

	for(int a = 0; !flag && a*HOUSE <= N; ++a)
	{
		for(int b = 0; !flag && b*CAR+a*HOUSE <= N; ++b)
		{
			if((N - (b*CAR+a*HOUSE)) % COMP == 0)
				flag = true;
		}
	}

	cout << (flag ? "YES" : "NO") << endl;
}