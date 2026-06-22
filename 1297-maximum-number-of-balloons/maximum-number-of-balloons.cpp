class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> letters(26, 0);

        for (char ch : text) {
            letters[ch - 'a']++;
        }

        return min({letters[0], letters[1], letters[11] / 2, letters[13], letters[14] / 2});
    }
};