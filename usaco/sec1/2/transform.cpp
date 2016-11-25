/*
ID: yassin.2
PROG: transform
LANG: C++11
*/
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int N;

bool t1(vector<string> tr, vector<string> orig)
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(tr[i][j] != orig[N-j-1][i])
				return false;
	return true;
}

bool t2(vector<string> tr, vector<string> orig)
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(tr[i][j] != orig[N-i-1][N-j-1])
				return false;
	return true;
}

bool t3(vector<string> tr, vector<string> orig)
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(tr[i][j] != orig[j][N-i-1])
				return false;
	return true;
}

bool t4(vector<string> tr, vector<string> orig)
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(tr[i][j] != orig[i][N-j-1])
				return false;
	return true;
}

bool t5(vector<string> tr, vector<string> orig)
{
	vector<string> pt(N, string(N, ' '));
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			pt[i][j] = tr[i][N-j-1];
	return t1(pt, orig) || t2(pt, orig) || t3(pt, orig);
}

bool t6(vector<string> tr, vector<string> orig)
{
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(tr[i][j] != orig[i][j])
				return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false);
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");

    fin >> N;

    vector<string> orig(N), tr(N);
    for(int i = 0; i < N; ++i)
    	fin >> orig[i];
    for(int i = 0; i < N; ++i)
    	fin >> tr[i];
    if(t1(tr, orig))
    	fout << 1 << endl;
    else if(t2(tr, orig))
    	fout << 2 << endl;
    else if(t3(tr, orig))
    	fout << 3 << endl;
	else if(t4(tr, orig))
    	fout << 4 << endl;
    else if(t5(tr, orig))
    	fout << 5 << endl;
    else if(t6(tr, orig))
    	fout << 6 << endl;
    else
    	fout << 7 << endl;
    return 0;
}