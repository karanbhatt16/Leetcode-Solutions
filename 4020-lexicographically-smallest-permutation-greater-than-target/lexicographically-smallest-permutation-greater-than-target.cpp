class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string temp = s;
        sort(temp.begin(), temp.end(), greater<char>());
        if (temp <= target) return "";
        vector<int> letters(26, 0);
        int n = s.length();
        for (int i = 0; i < n; i++) {
            letters[s[i] - 'a']++;
        }

        string ans = "";
        for (int i = 0; i < n; i++) {
            char ch = target[i];
            if (letters[ch - 'a'] == 0) {
                for (int i = (ch - 'a'); i < 26; i++) {
                    if (letters[i] > 0) {
                        ans += (i + 'a');
                        letters[i]--;
                        break;
                    }
                }
                break;
            }
            letters[ch - 'a']--;
            string a1 = "";
            for (int j = 25; j >= 0; j--) {
                int val = letters[j];
                while (val > 0) {
                    a1 += (j + 'a');
                    val--;
                }
            }
            string a2 = target.substr(i + 1, n - i - 1);

            if (a1 > a2) {
                ans += ch;
            } else {
                letters[ch - 'a']++;
                for (int i = (ch - 'a' + 1); i < 26; i++) {
                    if (letters[i] > 0) {
                        ans += (i + 'a');
                        letters[i]--;
                        break;
                    }
                    if (i == 25) return "";
                }
                break;
            }
        }
        for (int i = 0; i < 26; i++) {
            while (letters[i] > 0) {
                letters[i]--;
                ans += (i + 'a');
            }
        }
        return ans;
    }
};