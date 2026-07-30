class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (i % 8 == 0) {
                ans += (i / 8) * sum;
                sum = 0;
            }
            sum += freq[i];
        }
        ans += 4 * sum;
        return ans;
    }
};