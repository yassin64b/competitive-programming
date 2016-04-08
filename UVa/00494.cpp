#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
	int count = 0, flag = 0;
	string line;

	while(getline(cin, line))
	{
		count = 0; flag = 0;
		for(int i = 0; i < (int)line.size(); ++i)
		{
			if(isalpha(line[i]))
				flag = 1;
			else
			{
				if(flag)
					++count;

				flag = 0;
			}
		}
		cout << (flag ? count+1 : count) << endl;
	}		
	return 0;
}