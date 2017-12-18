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
    vector<int> V(2 * N);
    for (int i = 0; i < 2 * N; ++i)
        cin >> V[i];
    int cnt[2]{};
    for (int i = 0; i < 2 * N; ++i) {
        if (i % 2 == 0)
            cnt[0] += V[i] == 1, cnt[1] += V[i] == 0;
        else
            cnt[0] += V[i] == 0, cnt[1] += V[i] == 1;
    }
    //cout << cnt[0] << " " << cnt[1] << endl;
    cout << min(cnt[0], cnt[1]) / 2 << endl;
    
    return 0;
}