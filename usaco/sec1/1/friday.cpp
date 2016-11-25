/*
ID: yassin.2
PROG: friday
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

inline bool leapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main() {
	ios::sync_with_stdio(false);
    ofstream fout("friday.out");
    ifstream fin("friday.in");
    int N;
    fin >> N;

    int dayofweek = 0; //monday
    int dayofmonth = 1;
    int month = 0; //january
    int year = 1900;

    vector<int> v(7, 0);
    for(int i = 0; year < 1900 + N; ++i)
    {
    	if(dayofmonth == 13)
    		++v[dayofweek];

    	dayofweek = (dayofweek + 1) % 7;
    	++dayofmonth;
    	if(dayofmonth > 28 && month == 1 && !leapYear(year))
    	{
    		dayofmonth = 1, month = 2;
    	} 
    	else if(dayofmonth > 29 && month == 1)
    	{
    		dayofmonth = 1, month = 2;
    	}
    	else if(dayofmonth > 30 && 
    		(month == 3 || month == 5 || month == 8 || month == 10))
  		{
  			dayofmonth = 1, month += 1;
  		}	  			
  		else if(dayofmonth > 31)
  		{
  			dayofmonth = 1, month += 1;
  			if(month > 11)
  			{
  				month = 0, year += 1;
  			}
  		}
    }

    fout << v[5] << " " << v[6];
    for(int i = 0; i < 5; ++i)
    	fout << " " << v[i];
    fout << endl;
    return 0;
}