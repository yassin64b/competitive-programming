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
    string S;
    cin >> S;
    
    int cnt = 0, cur = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (S[i] == '0') {
            cur = 1;
        } else {
            if (i == 0 || S[i - 1] == '0') {
                cnt += cur + 1;
                cur = 0;
            }
        }
    }

    if (cnt % 2 == 1) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    
    return 0;
}