#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; ++t) {
        int N, M;
        cin >> N >> M;

        cout.precision(17);
        cout << "Case #" << t << ": " << fixed << (N - M) / (double)(N + M) << endl;
    }
}