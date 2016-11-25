/*
ID: yassin.2
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string comet, group;
    fin >> comet >> group;
    int val1 = 1, val2 = 1;
    for(int i = 0; i < (int)comet.size(); ++i)
    	val1 = (val1 * (comet[i] - 'A' + 1)) % 47;
    for(int i = 0; i < (int)group.size(); ++i)
    	val2 = (val2 * (group[i] - 'A' + 1)) % 47;
    if(val1 == val2)
    	fout << "GO" << endl;
    else
    	fout << "STAY" << endl;
    return 0;
}