class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        int n = words.size();
        string s = "";
        for (int i = 0; i < n; i++) {
            int m = words[i].length();
            int sum = 0;
            for (int j = 0; j < m; j++) {
                sum += weights[words[i][j] - 'a'];
            }
            int letter = sum % 26;
            s += 'a' + (26 - letter - 1);
        }
        return s;
    }
};