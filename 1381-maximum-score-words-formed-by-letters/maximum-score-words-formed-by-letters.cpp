class Solution {
private:
    int solve(vector<string>& words, vector<int>& score, unordered_map<char, int>& mp, int i, int ans) {
        if (i >= words.size()) return ans;
        int flag = 1;
        int sum = 0;
        int idx = words[i].length();
        for (int j = 0; j < words[i].length(); j++) {
            if (mp[words[i][j]] != 0) {
                mp[words[i][j]]--;
                sum += score[words[i][j] - 'a'];
            } else {
                flag = 0;
                idx = j;
                break;
            }
        }
        int a = 0;
        if (flag) {
            a = solve(words, score, mp, i + 1, ans + sum);
        }
        for (int j = 0; j < idx; j++) {
            mp[words[i][j]]++;
        }
        int b = solve(words, score, mp, i + 1, ans);
        return max(a, b);
    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char, int> mp;
        for (int i = 0; i < letters.size(); i++) {
            mp[letters[i]]++;
        }
        int ans = 0;
        return solve(words, score, mp, 0, ans);
    }
};