#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>

using namespace std;

double sum = 0;
bool nachkomma = false;

void add(string& s) 
{
	int n = s.size();
	double tmp = 0;
	if(n > 3 && s[n-3] == '.')
	{
		tmp = (s[n-2] - '0') * 0.1 + (s[n-1] - '0') * 0.01;
		nachkomma = true;
		//sum += tmp;
		n -= 3;
	}

	int mult = 1;
	for(int i = n-1; i >= 0; --i)
	{
		if(s[i] >= '0' && s[i] <= '9')
		{
			tmp += (s[i] - '0') * mult;
			mult *= 10;
		}
		
	}
	//cout << "hi" << s << " " << tmp << endl;
	sum += tmp;
	s = "";
}

int main()
{
	ios::sync_with_stdio(false);
	
	char c;
	bool flag = false;
	string s;
	while(cin >> c)
	{
		//cout << c << endl;
		if(c >= 'a' && c <= 'z')
		{
			if(flag == true)
			{
				add(s);
				flag = false;
			}
		} 
		else
			s += c, flag = true;
	}
	if(flag == true)
	{
		add(s);
		flag = false;
	}

	string res = to_string(sum);
	//cout << res << endl;
	res.erase ( res.find_last_not_of('0') + 1, std::string::npos );
	//cout << res << endl;
	if(res[res.size()-1] == '.')
		res.erase(res.size()-1, std::string::npos);
	else if(res[res.size()-2] == '.')
		res += '0';
	//cout << res << endl;
	int j;
	for(j = 0; j < (int)res.size(); ++j)
	{
		if(res[j] == '.')
		{
			--j;
			break;
		}
	}
	if(j == (int)res.size())
	{
		j = res.size()-1;
	}	
	int len = j+1;
	//cout << res << endl;
	if(len >= 10)
	{
		res = res.substr(0, len-10+1) + "." + res.substr(len-10+1, 3) + "." + res.substr(len-7+4, 3) + "." + res.substr(len-10+7);
	}
	else if(len >= 7)
	{
		res = res.substr(0, len-7+1) + "." + res.substr(len-7+1, 3) + "." + res.substr(len-7+4);
	} 
	else if(len >= 4)
	{
		res = res.substr(0, len-4+1) + "." + res.substr(len-4+1);
	}
	
	

	cout << res << endl;
	return 0;
}