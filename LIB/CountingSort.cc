void countingSort(vector<int> &v, int range) {
    vector<int> cnt(range + 1, 0);
    
    for (int i = 0; i < (int) v.size(); ++i) {
        ++cnt[v[i]];
    }
    
    for (int i = 0, j = -1; i <= range; ++i) {
        for (int k = 0; k < cnt[i]; ++k) {
            v[++j] = i;
        }
    }
}