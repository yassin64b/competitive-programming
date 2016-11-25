/*
ID: yassin.2
PROG: beads
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
	ios::sync_with_stdio(false);
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");
    string s;
    int N;
    fin >> N >> s;
    
    s = s + s + s;
    int maxcnt = 0;
    for(int i = N; i < 2 * N; ++i)
    {
    	char left = s[i-1];
    	int j = i-1, leftcnt = 0;
    	while(j >= 0 && (s[j] == left || s[j] == 'w' || left == 'w'))
    	{
    		if(left == 'w')
    			left = s[j];
    		++leftcnt, --j;
    	}	

    	char right = s[i];
 		j = i;
 		int rightcnt = 0;
 		while(j < (int)s.size() && (s[j] == right || s[j] == 'w' || right == 'w'))
 		{
 			if(right == 'w')
 				right = s[j];
 			++rightcnt, ++j;
 		}	

 		maxcnt = max(maxcnt, leftcnt + rightcnt);
    }


    fout << (maxcnt > N ? N : maxcnt) << endl;
    return 0;
}