#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int S, Q, K;
    cin >> S >> Q >> K;
    vector<int> P(Q);
    for (int i = 0; i < Q; ++i)
        cin >> P[i];
    sort(P.begin(), P.end());
    double res = S;
    for (int i = 0; i < Q; ++i) {
        if (res * (1. + P[i] / 100.) > res + K) 
            res *= (1. + P[i] / 100.);
        else
            res += K;
    }
    cout.precision(17);
    cout << fixed << res << endl;
    
    return 0;
}