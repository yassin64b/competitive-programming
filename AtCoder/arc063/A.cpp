#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{
    string S;
    cin >> S;
    char last = S[0];
    int cnt = 0;
    for(int i = 1; i < (int)S.size(); ++i)
    {
        if(S[i] != last)
        {
            last = S[i];
            ++cnt;
        }
    }
    cout << cnt << endl;
    return 0;
}