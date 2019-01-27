#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    int N, A, B;
    cin >> N >> A >> B;

    cout << min(A, B) << " " << max(0, A + B - N) << "\n";

    return 0;
}