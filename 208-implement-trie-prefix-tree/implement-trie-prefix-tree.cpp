struct Node {
    Node* links[26];
    bool flag;

    bool containsChar(char ch) {
        return links[ch - 'a'] == NULL;
    }
    
    void putChar(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* nextNode(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsChar(word[i])) {
                node->putChar(word[i], new Node());
            }
            node = node->nextNode(word[i]);
        }
        node->flag = true;
    }
    
    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsChar(word[i])) {
                return false;
            }
            node = node->nextNode(word[i]);
        }
        if (node->flag == false) {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (node->containsChar(prefix[i])) {
                return false;
            }
            node = node->nextNode(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */