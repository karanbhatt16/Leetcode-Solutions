class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> letters(52, 0);

        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] < 'a') {
                letters[s[i] - 'A' + 26]++;
            } else {
                letters[s[i] - 'a']++;
            }
        }

        int count = 0;

        for (int i = 0; i < 52; i++) {
            if (letters[i] > 1) {
                count += letters[i] & 1 ? letters[i] - 1 : letters[i];
            }
        }

        if (count < n) {
            return count + 1;
        }

        return count;
    }
};