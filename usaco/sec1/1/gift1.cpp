/*
ID: yassin.2
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    
    int NP;
    fin >> NP;

    vector<string> m(NP);
    for(int i = 0; i < NP; ++i)
    {
    	string name;
    	fin >> name;
    	m[i] = name;
    }

    map<string, int> v, orig;
    for(int i = 0; i < NP; ++i)
    {
    	string giver;
    	int amount, NG;
    	fin >> giver >> amount >> NG;
    	v[giver] += (orig[giver] = amount);
    	for(int j = 0; j < NG; ++j)
    	{
    		string rec;
    		fin >> rec;
    		v[rec] += amount / NG;
    	}
    	if(NG != 0) 
    		v[giver] -= (amount / NG) * NG;
    }

    for(int i = 0; i < NP; ++i)
    {
    	fout << m[i] << " " << v[m[i]] - orig[m[i]] << endl;
    }

    return 0;
}