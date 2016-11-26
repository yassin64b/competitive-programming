#include <iostream>
#include <string>

using namespace std;

int main() 
{
	int N; 
	cin >> N;

	std::string res = "NO";
	for(int i = 0; i < N; ++i)
	{
		std::string s;
		cin >> s;

		int b, a;
		cin >> b >> a;

		if(b >= 2400 && a > b)
		{
			res = "YES";
			break;
		}
	}

	cout << res << endl;
}
