class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> letters(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            letters[s[i] - 'a'] = i;
        }
        int last = 0;
        vector<int> ans;
        int count = 0;
        for (int i = 0; i < n; i++) {
            last = max(last, letters[s[i] - 'a']);
            count++;
            if (last == i) {
                ans.push_back(count);
                count = 0;
            }
        }
        return ans;
    }
};