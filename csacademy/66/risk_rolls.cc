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
    vector<int> a(N), b(M);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < M; ++i) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ra = 0, rb = 0;
    while (!a.empty() && !b.empty()) {
        if (a.back() > b.back()) {
            ra += 1;
        } else {
            rb += 1;
        }
        a.pop_back();
        b.pop_back();
    }
    cout << ra << " " << rb << endl;

    return 0;
}