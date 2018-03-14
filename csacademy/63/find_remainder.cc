#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    for (int i = 0; i < N; ++i)
        cin >> B[i];
    
    int mn = *max_element(B.begin(), B.end());
    int mx = -1;
    for (int i = 0; i < N; ++i) {
        if (A[i] > B[i])
            mx = max(mx, A[i]);
    }
    if (mx == -1)
        mx = 2'000'000'000;
        
    set<int> ds;
    ds.insert(mn + 1);
    for (int i = 0; i < 10 && i < N; ++i) {
        if (B[i] > A[i]) {
            cout << -1 << endl;
            return 0;
        } else if (B[i] != A[i]) {
            if (A[i] - B[i] > mn && A[i] - B[i] < mx)
                ds.insert(A[i] - B[i]);
        }
    }
    set<int> divs;
    for (int d : ds) {
        for (int i = 1; i * i <= d; ++i) {
            if (d % i == 0) {
                if (i >= mn && i <= mx)
                    divs.insert(i);
                if (i != d / i && d / i >= mn && d / i <= mx)
                    divs.insert(d / i);
            }
        }
    }
    
    //sort(divs.begin(), divs.end());
    for (int k : divs) {
        bool ok = true;
        for (int i = 0; ok && i < N; ++i) {
            if (B[i] != A[i] % k)
                ok = false;
        }
        if (ok) {
            cout << k << "\n";
            return 0;
        }
    }
    cout << -1 << "\n";
    return 0;
}