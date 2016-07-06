#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>

using namespace std;

int main() 
{
	int N;
	cin >> N;

	string s;
	cin >> s;

	bool bot = false, top = false, left = false, right = false;
	for(int i = 0; i < N; ++i)
	{
		if(s[i] == '1' || s[i] == '2' || s[i] == '3')
			top = true;
		if(s[i] == '1' || s[i] == '4' || s[i] == '7' || s[i] == '0')
			left = true;
		if(s[i] == '3' || s[i] == '6' || s[i] == '9' || s[i] == '0')
			right = true;
		if(s[i] == '7' || s[i] == '9' || s[i] == '0')
			bot = true;
	}

	if((left == true && right == true) && (top == true && bot == true))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}