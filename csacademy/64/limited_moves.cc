#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    
    int num = 1;
    for (int i = 1; i <= N - 1; ++i) {
        if (N % i == 0 && (N / i) % 2 == 1) {
            num = i;
            break;
        }
    }
    for (int i = 0; i < 500; ++i) {
        cout << num << "\n";
        cout.flush();
        cin >> num;
    }
    
    return 0;
}