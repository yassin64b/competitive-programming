#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

constexpr int MOD = 1000 * 1000 * 1000 + 7;
int K = 50;

typedef long long int64;
typedef vector<vector<int64>> matrix;

matrix mul(const matrix& A, const matrix& B) {
    matrix C(K + 1, vector<int64>(K + 1, 0));
    for (int i = 1; i <= K; ++i) 
    	for (int j = 1; j <= K; ++j)
    		for (int k = 1; k <= K; ++k)
        		C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

matrix pow(const matrix& A, int p) {
	if (p == 1) {
		return A;
	} else if (p % 2 == 1) {
		return mul(A, pow(A, p - 1));
	}
	matrix tmp = pow(A, p / 2);
	return mul(tmp, tmp);
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N, Z;
		cin >> N >> Z;
		vector<int> trains(Z);
		K = 1;
		for (int i = 0; i < Z; ++i) {
			cin >> trains[i];
			K = max(K, trains[i]);
		}
		vector<int64> F(K + 1, 0);
		F[0] = 1;
		for (int j = 0; j <= K; ++j) {
			for (int i = 0; i < Z; ++i) {
				if (j + trains[i] <= K) {
					F[j + trains[i]] += F[j];
					F[j + trains[i]] %= MOD;
				}
			}
		}

		matrix T(K + 1, vector<int64>(K + 1, 0));
		for (int i = 1; i <= K - 1; ++i) {
			T[i][i + 1] = 1;
		}
		for (int j = 0; j < Z; ++j) {
			T[K][K - trains[j] + 1] += 1;
		}
		
		T = pow(T, N);
		
		int res = 0;
		for (int i = 1; i <= K; ++i) {
			res += (T[1][i] * F[i - 1]) % MOD;
			res %= MOD;
		}
		if (res == 0) {
			cout << "IMPOSSIBLE\n";
			continue;
		}
		cout << res << "\n";

	}



	return 0;
}