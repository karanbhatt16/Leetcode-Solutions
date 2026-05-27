class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> v(52, 0);
        for (int i = 0; i < word.size(); i++) {
            if (word[i] >= 97) {
                if (v[word[i] - 'a'] > 0) {
                    v[word[i] - 'a' + 26] = INT_MIN;
                }
                v[word[i] - 'a' + 26]++;
                continue;
            }
            v[word[i] - 'A']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (v[i] > 0 && v[i + 26] > 0) {
                count++;
            } 
        }
        return count;
    }
};