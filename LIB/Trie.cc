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

int count_words(Trie& node, const string& word, int i) {
    if (i >= (int)word.size())
        return node.words;
    else {
        int k = word[i] - 'a';
        if (node.edges[k] == nullptr)
            return 0;
        else {
            return count_words(*node.edges[k], word, i + 1);
        }
    }
}
