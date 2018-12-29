#include <bits/stdc++.h>

using namespace std;

struct Trie {
    Trie *edges[26]{};
};

void add_word(Trie& node, const string& word, int i, int left, const string &good) {
    if (i >= (int)word.size()) {
        return;
    }
    int k = word[i] - 'a';
    left -= !good[k];
    if (left >= 0) {
        if (node.edges[k] == nullptr) {
            node.edges[k] = new Trie();
        }
        add_word(*node.edges[k], word, i + 1, left, good);
    }
    
}

int destruct(Trie &node) {
    int cnt = 1;
    for (int i = 0; i < 26; ++i) {
        if (node.edges[i] != nullptr) {
            cnt += destruct(*node.edges[i]);
        }
    }
    //delete &node;
    return cnt;
}

int main() {
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr);
    
    string s, good;
    int k;
    cin >> s >> good >> k;
    for (char &c : good) {
        c -= '0';
    }

    int n = s.size();
    Trie t;
    for (int i = 0; i < n; ++i) {
        add_word(t, s, i, k, good);
    }
    cout << destruct(t) - 1 << "\n";

    return 0;
}