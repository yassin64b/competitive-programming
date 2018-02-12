long long count_inv(int *a, int n) {
    if (n <= 1) {
        return 0;
    }
    int sz1 = n / 2, sz2 = n - sz1;
    long long num_inv = count_inv(a, sz1) + count_inv(a + sz1, sz2);
    vector<int> old1(a, a + sz1), old2(a + sz1, a + n);
    int k = 0, i = 0, j = 0;
    while (i < sz1 && j < sz2) {
        if (old1[i] <= old2[j]) {
            a[k++] = old1[i++];
            num_inv += j;
        } else {
            a[k++] = old2[j++];
        }
    }
    while (i < sz1) {
        a[k++] = old1[i++];
        num_inv += j; //j == n - m
    }
    while (j < sz2) {
        a[k++] = old2[j++];
    }
    return num_inv;
}