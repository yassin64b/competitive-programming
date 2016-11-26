#include <iostream>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;
	if(n == 1) 
	{
		int x;
		cin >> x;
		if(x == 0)
			cout << "UP" << endl;
		else if(x == 15)
			cout << "DOWN" << endl;
		else
			cout << - 1 << endl;
		return 0;
	}

	int x = 0, y;
	for(int i = 0; i < n; ++i)
	{
		y = x;
		cin >> x;
	}

	if(y < x)
	{
		if(x == 15)
			cout << "DOWN" << endl;
		else
			cout << "UP" << endl;
	}
	else
	{
		if(x == 0)
			cout << "UP" << endl;
		else
			cout << "DOWN" << endl;
	}
    return 0;
}