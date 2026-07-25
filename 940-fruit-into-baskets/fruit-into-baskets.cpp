class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        vector<int> freq(n, 0);
        int count = 0;
        int mx = 0;
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (freq[fruits[i]] == 0) count++;
            freq[fruits[i]]++;
            while (count > 2) {
                freq[fruits[j]]--;
                if (freq[fruits[j]] == 0) count--;
                j++;
            }
            mx = max(mx, i - j + 1);
        }
        return mx;
    }
};