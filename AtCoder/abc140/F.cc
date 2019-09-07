#include <bits/stdc++.h>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    int N;
    cin >> N;
    int len = (1 << N);
    vector<int> S(len);
    multiset<int> todo;
    for (int i = 0; i < len; ++i) {
        cin >> S[i];
        todo.insert(S[i]);
    }
    vector<int> act;
    auto it = --end(todo);
    act.push_back(*it);
    todo.erase(it);

    for (int i = 0; i < N; ++i) {
        int m = act.size();
        for (int j = 0; j < m; ++j) {
            it = todo.lower_bound(act[j]);
            if (it == begin(todo)) {
                cout << "No\n";
                return 0;
            }
            --it;
            act.push_back(*it);
            todo.erase(it);
        }
    }
    cout << "Yes\n";

    return 0;
}