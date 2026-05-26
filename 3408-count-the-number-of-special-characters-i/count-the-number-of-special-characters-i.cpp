class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> s;
        for (int i = 0; i < word.length(); i++) {
            for (int j = i + 1; j < word.length(); j++) {
                if (abs(word[i] - word[j]) == 32) {
                    s.insert(word[i]);
                    s.insert(word[j]);
                }
            }
        }
        return s.size() / 2;
    }
};