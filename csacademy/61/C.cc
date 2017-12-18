#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> lr(M);
    vector<int> boards(N + 1, 0);
    for (int i = 0; i < M; ++i) {
        cin >> lr[i].first >> lr[i].second;
        --lr[i].first; 
        --lr[i].second;
        boards[lr[i].first] += 1;
        boards[lr[i].second + 1] -= 1;
    }
    int everyone = boards[0] == 0;
    vector<int> ones;
    if (boards[0] == 1) ones.push_back(0);
    for (int i = 1; i < N; ++i) {
        boards[i] += boards[i - 1];
        if (boards[i] == 0)
            ++everyone;
        else if (boards[i] == 1)
            ones.push_back(i);
    }
    /*cout << everyone << endl;
    for (int x : ones)
        cout << x << " ";
    cout << endl;*/
    for (int i = 0; i < M; ++i) {
        auto it = lower_bound(ones.begin(), ones.end(), lr[i].first);
        auto it2 = upper_bound(ones.begin(), ones.end(), lr[i].second);
        //cout << lr[i].first << "," << lr[i].second << ":\n";
        //cout << *it << " " << *it2 << endl;
        if (it2 != ones.begin()) {
            --it2;
            //cout << *it << " " << *it2 << endl;
            cout << it2 - it + 1 + everyone << "\n";
        } else {
            cout << 0 + everyone << "\n";
        }
    }
    
    return 0;
}