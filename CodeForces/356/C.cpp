#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	vector<int> v{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};

	int cnt = 0;
	for(int i = 0; cnt < 2 && i < (int)v.size(); ++i)
	{
		cout << v[i] << endl;

		string answer;
		cin >> answer;

		if(answer == "yes")
		{
			++cnt;

			if(v[i]*v[i] <= 100)
			{
				cout << v[i]*v[i] << endl;
				cin >> answer;
				if(answer == "yes")
					++cnt;
			}
			
		}	
	}

	if(cnt < 2)
		cout << "prime" << endl;
	else
		cout << "composite" << endl;
}