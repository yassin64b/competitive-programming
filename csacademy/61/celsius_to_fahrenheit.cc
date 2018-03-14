#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int C;
    cin >> C;
    
    C = C * 1.8 + 32;
    
    cout << C << endl;
    
    return 0;
}