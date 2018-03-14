#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    vector<int> B(A);
    sort(B.begin(), B.end());
    if (A == B) {
        long long num = 0;
        for (int i = 0; i < N; ) {
            int j = i;
            while (j < N && A[i] == A[j]) {
                ++j;
            }
            int len = j - i;
            num += 1LL * len * (len + 1) / 2;
            i = j;
        }
        cout << num << "\n" << 1 << " " << 1 << "\n";
        return 0;
    }
    vector<int> smn(N);
    smn[N - 1] = A[N - 1];
    for (int i = N - 2; i >= 0; --i) {
        smn[i] = min(A[i], smn[i + 1]);
    }
    int start = -1, mn = -1;
    for (int i = 0; i + 1 < N; ++i) {
        if (A[i] > smn[i + 1]) {
            start = i;
            mn = smn[i + 1];
            break;
        }
    }
    assert(start != -1);
    int end = -1;
    for (int i = start; i < N; ++i) {
        if (A[i] == mn) {
            end = max(end, i);   
        }
    }
    reverse(A.begin() + start, A.begin() + end + 1);
    if (A == B) {
        cout << 1 << "\n" << start + 1 << " " << end + 1 << "\n";
        return 0;
    }
    cout << 0 << endl;
    return 0;
}