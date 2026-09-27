class Solution {
private:
    bool solve(string& s, set<string>& dict, int idx, vector<int>& dp) {
        if (idx >= s.length()) {
            return true;
        }
        if (dp[idx] != -1) {
            return dp[idx];
        }
        for (int i = idx; i < s.length(); i++) {
            if (dict.find(s.substr(idx, i - idx + 1)) != dict.end()) {
                if (solve(s, dict, i + 1, dp)) {
                    return dp[idx] = true;
                }
            }
        }
        return dp[idx] = false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> dict;
        int n = wordDict.size();
        vector<int> dp(s.length(), -1);
        for (int i = 0; i < n; i++) {
            dict.insert(wordDict[i]);
        }
        return solve(s, dict, 0, dp);
    }
};