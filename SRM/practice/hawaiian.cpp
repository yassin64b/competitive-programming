#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Hawaiian
{
public:
	vector<string> getWords(string s)
	{
		vector<string> res;
		string tmp;
	
		bool flag = false;
		for(int i = 0; i < (int)s.size(); ++i)
		{
			if(s[i] == ' ')
			{
				if(tmp != "" && !flag)
					res.push_back(tmp);
				tmp = "";
				flag = false;
			}
			else
			{
				char c = tolower(s[i]);
				if(c == 'a' || c == 'e' || c == 'u' || c == 'w' || (c - 'h' >= 0 && c - 'h' <= 8 && c != 'j')) 
					tmp += s[i];
				else
					flag = true;
			}
		}
		if(tmp != "" && !flag)
			res.push_back(tmp);
		return res;
	}
};