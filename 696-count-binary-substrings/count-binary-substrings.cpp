class Solution {
public:
    int countBinarySubstrings(string s) {
        int count = 1;
        int ans = 0;
        int prev = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] != s[i + 1]){
                ans += min(prev, count);
                prev = count;
                count = 1;
            } else {
                count ++;
            }
        }
        ans += min(prev, count);
        return ans;
    }
};