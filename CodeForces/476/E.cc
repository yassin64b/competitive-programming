#include <bits/stdc++.h>

using namespace std;

struct Trie {
    int words;
    int prefixes;
    Trie *edges[26];
};

void init(Trie& node) {
    node.words = node.prefixes = 0;
    for (int i = 0; i < 26; ++i)
        node.edges[i] = nullptr;
}

void add_word(Trie& node, const string& word, int i) {
    if (i >= (int)word.size())
        node.words += 1;
    else {
        node.prefixes += 1;
        int k = word[i] - 'a';
        if (node.edges[k] == nullptr) {
            node.edges[k] = new Trie();
            init(*node.edges[k]);
        }
        add_word(*node.edges[k], word, i + 1);
    }
}

void merge(multiset<int> &lhs, multiset<int> &rhs) {
    if (lhs.size() < rhs.size()) {
        swap(lhs, rhs);
    }
    for (int x : rhs) { // move smaller sized set to larger set
        lhs.insert(x);
    }
}

multiset<int> dfs(Trie &cur, int d) {
    multiset<int> ans;
    for (int i = 0; i < 26; ++i) {
        if (cur.edges[i]) { // get word lengths of subtree
            multiset<int> tmp(dfs(*cur.edges[i], d + 1));
            merge(ans, tmp);
        }
    }
    if (cur.words) {
        ans.insert(d); // add current word length
    } else if (d) {
        assert(!ans.empty());
        ans.erase(--ans.end()); // move longest below up to current depth
        ans.insert(d);
    }
    return ans;
}

class TaskE {
public:
    void solve(istream& in, ostream& out) {
        int n;
        in >> n;
        vector<string> v(n);
        Trie *root = new Trie();
        init(*root);
        for (int i = 0; i < n; ++i) {
            in >> v[i];
            add_word(*root, v[i], 0);
        }
        multiset<int> ans(dfs(*root, 0));
        out << accumulate(begin(ans), end(ans), 0) << "\n";
    }
};

int main() {
    std::ios::sync_with_stdio(false); cin.tie(nullptr);
    TaskE solver;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    solver.solve(in, out);
    return 0;
}
