/*
ID: yassin.2
PROG: milk2
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");
    int N;
    fin >> N;

    vector<pair<int,int>> v(N);
    for(int i = 0; i < N; ++i)
    	fin >> v[i].first >> v[i].second;
    
    sort(v.begin(), v.end());
    int maxone = 0, maxno = 0;
    int startone = v[0].first, covered = v[0].second;
    for(int i = 1; i < N; ++i)
    {
    	if(v[i].first <= covered)
    		covered = max(covered, v[i].second);
    	else
    	{
    		maxno = max(maxno, v[i].first - covered);
    		maxone = max(maxone, covered - startone);
    		startone = v[i].first, covered = v[i].second;
    	}
    }

    fout << max(maxone, covered - startone) << " " << maxno << endl;
    return 0;
}