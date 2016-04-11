#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Quacking
{
public:
    int quack(string s)
    {
        vector<int> v;
        int count = 0;
        bool found, complete;

        for(int i = 0; i < (int)s.size(); ++i)
        {
            found = false;
            int j;

            for(j = 0; j < (int)v.size(); ++j)
            {
                switch(s[i])
                {
                case 'q': if(v[j]%5 == 0) found = true; break;
                case 'u': if(v[j]%5 == 1) found = true; break;
                case 'a': if(v[j]%5 == 2) found = true; break;
                case 'c': if(v[j]%5 == 3) found = true; break;
                case 'k': if(v[j]%5 == 4) found = true; break;
                }
                if(found) break;

            }
            if(found)
                ++v[j];
            else
            {
                if(s[i] != 'q') return -1;
                v.push_back(1);
                ++count;
            }
        }
        complete = true;
        for(int i = 0; complete && i < (int) v.size(); ++i)
        	if(v[i]%5 != 0) complete = false;
        return complete ? count : -1;
    }
};