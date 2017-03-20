#include <iostream>

using namespace std;

int main() 
{
	int N;
	cin >> N;

	int last = 0, cur;
	bool flag = true;
	for(int i = 0; i < N; ++i) 
	{
		cin >> cur;
		if(cur < last) 
			flag = false;
		last = cur;
	}
	cout << (flag ? "yes" : "no") << endl;
	return 0;
}