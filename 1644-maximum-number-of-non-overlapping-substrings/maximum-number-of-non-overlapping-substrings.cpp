class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> start(26, -1);
        vector<int> end(26, -1);
        vector<int> isValid(n, 1);

        for (int i = 0; i < n; i++) {
            if (start[s[i] - 'a'] == -1) {
                start[s[i] - 'a'] = i;
            }
            end[s[i] - 'a'] = i;
        }

        for (int c = 0; c < 26; c++) {
            if (start[c] == -1) {
                continue;
            }

            for (int i = start[c]; i <= end[c]; i++) {
                if (start[s[i] - 'a'] < start[c]) {
                    isValid[start[c]] = 0;
                    break;
                }
                if (end[s[i] - 'a'] > end[c]) {
                    end[c] = end[s[i] - 'a'];
                }
            }

            cout << start[c] << " " << end[c] << "\n";
        }

        int lastIdx = INT_MAX;
        vector<string> ans;
        for (int i = n - 1; i >= 0; i--) {
            cout << isValid[i] << " ";
            if (!isValid[i]) continue;
            if (start[s[i] - 'a'] == i && end[s[i] - 'a'] < lastIdx) {
                int length = end[s[i] - 'a'] - start[s[i] - 'a'] + 1;
                ans.push_back(s.substr(i, length));
                lastIdx = i;
            }
        }
        return ans;
    }
};