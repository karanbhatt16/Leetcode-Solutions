class Solution {
private:
    vector<vector<string>> result;
    void solve(unordered_map<string, int>& mp, string& beginWord, string& endWord, vector<string> temp) {
        int length = beginWord.length();
        if (beginWord == endWord) {
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }
        if (mp.find(beginWord) == mp.end()) {
            return;
        }

        for (int i = 0; i < length; i++) {
            string s = beginWord;
            for (int j = 0; j < 26; j++) {
                s[i] = char('a' + j);
                if (mp.find(s) != mp.end() && mp[s] == mp[beginWord] - 1) {
                    temp.push_back(s);
                    solve(mp, s, endWord, temp);
                    temp.pop_back();
                }
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int length = beginWord.length();

        unordered_map<string, int> mp;

        unordered_set<string> wordSet;
        for (string s : wordList) {
            wordSet.insert(s);
        }

        queue<string> q;
        q.push(beginWord);
        wordSet.erase(beginWord);
        mp[beginWord] = 0;

        while (!q.empty()) {
            string st = q.front();
            q.pop();

            for (int i = 0; i < length; i++) {
                string newst = st;
                for (int j = 0; j < 26; j++) {
                    newst[i] = char('a' + j);

                    if (wordSet.find(newst) != wordSet.end()) {
                        q.push(newst);
                        mp[newst] = mp[st] + 1;
                        wordSet.erase(newst);
                    }
                }
            }
        }

        vector<string> temp;
        temp.push_back(endWord);
        solve(mp, endWord, beginWord, temp);
        return result;
    }
};