void comp_ncr() {
    ncr.assign(1000 + 1, vector<int>(1000 + 1));
    for(int i = 0; i <= 1000; i++) {
        ncr[i][0] = 1;
    }
    for(int i = 1; i <= 1000; i++) {
        for(int j = 1; j <= 1000; j++) {
            ncr[i][j] = (ncr[i - 1][j - 1] + ncr[i - 1][j]) % MOD;
        }
    }
}