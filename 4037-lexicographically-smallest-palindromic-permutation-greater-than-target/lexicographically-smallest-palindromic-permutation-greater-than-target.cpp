class Solution {
private:
    int n;
    string ch;
    string result = "";
    bool solve(string& curr, string& target, int i, vector<int>& half, bool isGreater) {
        if (curr.length() == n / 2) {
            string temp = curr;
            reverse(temp.begin(), temp.end());
            string palindrome = curr + ch + temp;
            if (palindrome > target) {
                result = palindrome;
                return true;
            }
            return false;
        }

        for (int j = 0; j < 26; j++) {
            if (half[j] == 0) continue;
            if (!isGreater && (j + 'a') < target[i]) continue;
            curr.push_back((j + 'a'));
            half[j]--;

            bool greater = isGreater || (j + 'a') > target[i];
            if (solve(curr, target, i + 1, half, greater)) {
                return true;
            }

            half[j]++;
            curr.pop_back();
        }

        return false;
    }
public:
    string lexPalindromicPermutation(string s, string target) {
        n = s.length();
        vector<int> letters(26, 0);
        for (int i = 0; i < n; i++) {
            letters[s[i] - 'a']++;
        }
        vector<int> half(26, 0);
        ch = "";
        int odd = 0;
        for (int i = 0; i < 26; i++) {
            if (letters[i] % 2 == 1) {
                odd++;
                ch = (i + 'a');
            }
            half[i] = letters[i] / 2;
        }
        if (odd > 1) {
            return "";
        }

        string curr = "";
        solve(curr, target, 0, half, false);
        return result;
    }
};