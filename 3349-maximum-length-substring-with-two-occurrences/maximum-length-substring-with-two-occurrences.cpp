class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int length = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
            while (freq[s[i] - 'a'] > 2) {
                freq[s[j] - 'a']--;
                j++;
            }
            length = max(length, i - j + 1);
        }
        return length;
    }
};