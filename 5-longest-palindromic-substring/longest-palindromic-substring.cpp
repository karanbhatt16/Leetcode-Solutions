class Solution {
private:
    int longest = 0;
    int idx = -1;
    int count = 0;

    void findlongest(string s, int left, int right, int n) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            count += 2;
            left--;
            right++;
        }
        if (longest < count + 1) {
            longest = count + 1;
            idx = left + 1;
        }
    }
public:
    string longestPalindrome(string s) {

        int n = s.length();

        for (int i = 0; i < n; i++) {

            int left = i - 1;
            int right = i + 1;

            if (left >= 0 && s[left] == s[i]) {
                left--;
                count = 1;
                findlongest(s, left, right, n);
            }

            left = i - 1;
            count = 0;

            if (right < n && s[right] == s[i]) {
                right++;
                count = 1;
                findlongest(s, left, right, n);
            }

            right = i + 1;
            count = 0;

            findlongest(s, left, right, n);
        }
        return s.substr(idx, longest);
    }
};