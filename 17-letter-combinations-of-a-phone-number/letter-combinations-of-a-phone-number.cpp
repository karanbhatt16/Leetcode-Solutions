class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        int n = digits.size();
        vector<int> vec(n, 0);
        int k = 0;
        vector<string> ans;
        for (int i = 0; i < mp[digits[0]].size(); i++) {
            string res = "";
            res += mp[digits[0]][i];
            if (digits.size() > 1) {
                for (int j = 0; j < mp[digits[1]].size(); j++) {
                    res += mp[digits[1]][j];
                    if (digits.size() > 2) {
                        for (int k = 0; k < mp[digits[2]].size(); k++) {
                            res += mp[digits[2]][k];
                            if (digits.size() > 3) {
                                for (int l = 0; l < mp[digits[3]].size(); l++) {
                                    res += mp[digits[3]][l];
                                    ans.push_back(res);
                                    res.pop_back();
                                }
                                res.pop_back();
                                continue;
                            }
                            ans.push_back(res);
                            res.pop_back();
                        }
                        res.pop_back();
                        continue;
                    }
                    ans.push_back(res);
                    res.pop_back();
                }
                res.pop_back();
                continue;
            }
            ans.push_back(res);
            res.pop_back();
        }
        return ans;
    }
};