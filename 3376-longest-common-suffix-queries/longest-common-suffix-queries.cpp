class Solution {
public:

    struct Node {
        int links[26];
        int count;

        Node(int idx = 0) {
            for (int i = 0; i < 26; i++) {
                links[i] = -1;
            }
            count = idx;
        }
    };

    vector<Node> trie;

    Solution() {
        trie.push_back(Node(0));
    }

    bool better(int a, int b, vector<string>& wordsContainer) {

        if (wordsContainer[a].length() != wordsContainer[b].length()) {
            return wordsContainer[a].length() >
                   wordsContainer[b].length();
        }

        return a > b;
    }

    void insert(int x, vector<string>& wordsContainer) {

        string& word = wordsContainer[x];

        int node = 0;

        if (better(trie[node].count, x, wordsContainer)) {
            trie[node].count = x;
        }

        for (int i = word.length() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].links[c] == -1) {

                trie[node].links[c] = trie.size();

                trie.push_back(Node(x));
            }

            node = trie[node].links[c];

            if (better(trie[node].count, x, wordsContainer)) {
                trie[node].count = x;
            }
        }
    }

    int search(string& word) {

        int node = 0;

        for (int i = word.length() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].links[c] == -1) {
                return trie[node].count;
            }

            node = trie[node].links[c];
        }

        return trie[node].count;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        trie[0].count = 0;

        for (int i = 1; i < wordsContainer.size(); i++) {

            if (better(trie[0].count, i, wordsContainer)) {
                trie[0].count = i;
            }
        }

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(i, wordsContainer);
        }

        vector<int> ans;

        for (auto& q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};