class Solution {
private:
    bool chain(string& a, string& b) {
        int count = 0;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] != b[j]) {
                count++;
                j++;
                continue;
            }
            i++;
            j++;
        }
        if (count > 1) {
            return false;
        }
        return true;
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        int n = words.size();

        vector<int> ans(n, 1);
        int res = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (words[i].length() == words[j].length() + 1 && chain(words[j], words[i])) {
                    if (ans[i] < ans[j] + 1) {
                        ans[i] = ans[j] + 1;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) {
            res = max(res, ans[i]);
        }
        return res;

    }
};