#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
   
    int N;
    string s;
    cin >> N >> s;
	
    vector<int> v;
    bool black = false;
    int cur = 0;
    for(int i = 0; i < N; ++i)
    {
    	if(s[i] == 'B')
    		++cur;
    	else if(cur != 0)
    	{
    		v.push_back(cur);
    		cur = 0;
    	}
    }
    if(cur != 0)
    	v.push_back(cur);

    cout << v.size() << endl;
    for(int& a: v)
    	cout << a << " ";
    cout << endl;
	return 0;
}