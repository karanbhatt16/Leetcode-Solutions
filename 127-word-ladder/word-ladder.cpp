class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        string s;
        int n = beginWord.length();
        q.push(beginWord);
        int count = 1;
        unordered_set<string> wordSet;
        for (auto word : wordList) {
            wordSet.insert(word);
        }
        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                auto begin = q.front();
                q.pop();
                for (int i = 0; i < n; i++) {
                    s = begin;
                    for (int j = 0; j < 26; j++) {
                        s[i] = char('a' + j);
                        if (wordSet.find(s) != wordSet.end()) {
                            if (s == endWord) {
                                return count + 1;
                            }
                            q.push(s);
                            wordSet.erase(s);
                        }
                    }
                }
            }
            count++;
        }
        return 0;
    }
};