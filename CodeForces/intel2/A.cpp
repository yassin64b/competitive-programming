#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;

map<string,int> days{{"monday",0}, {"tuesday",1}, {"wednesday",2},
 {"thursday",3}, {"friday",4}, {"saturday",5}, {"sunday",6}};
int main()
{
	ios::sync_with_stdio(false);
	string day1, day2;
	cin >> day1 >> day2;
	//cout << days[day1] << " " << days[day2] << endl;
	if(days[day2] == (days[day1] + 3) % 7 ||
		days[day2] == (days[day1] + 2) % 7 ||
		days[day2] == days[day1])
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}