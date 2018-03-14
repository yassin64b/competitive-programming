using matrix = vector<vector<int>>;

matrix mul(const matrix& A, const matrix& B) {
    matrix C(5 + 1, vector<int>(5 + 1, 0));
    for (int i = 1; i <= 5; ++i) 
        for (int j = 1; j <= 5; ++j)
            for (int k = 1; k <= 5; ++k)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % 10;
    return C;
}

matrix pow(matrix &A, int p) {
    matrix res(5 + 1, vector<int>(5 + 1, 0));
    for (int i = 0; i <= 5; ++i) {
        res[i][i] = 1;
    }
    while (p > 0){
        if (p%2 == 1){
            res = mul(res, A);
        }
        A = mul(A, A);
        p /= 2;
    }
    return res;
}