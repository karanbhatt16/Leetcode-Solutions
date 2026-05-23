class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> letters;
        int maxi = 0;
        int idx = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (letters[s[i]] != 0 && letters[s[i]] > idx) {
                maxi = max(maxi, i - idx);
                idx = letters[s[i]];
            }
            letters[s[i]] = i + 1;
        }
        maxi = max(maxi, n - idx);
        return maxi;
    }
};