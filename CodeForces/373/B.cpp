#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

int main() 
{
	ios::sync_with_stdio(false);
    
    int n, cnt = 0, wcnt1b = 0, wcnt2b = 0, wcnt1r = 0, wcnt2r = 0;
    string s;

    cin >> n >> s;

    for(int i = 0; i < n; i += 2)
    {
    	if(s[i] == 'r')
    		++wcnt2b;
    	else
    		++wcnt1r;
    }
    for(int i = 1; i < n; i += 2)
    {
    	if(s[i] == 'b')
    		++wcnt2r;
    	else
    		++wcnt1b;
    }
    
    //cout << wcnt1b << " " << wcnt1r << " " << wcnt2b << " " << wcnt2r << endl;
    cout << min(max(wcnt1b, wcnt1r), max(wcnt2b, wcnt2r)) << endl;
    return 0;
}