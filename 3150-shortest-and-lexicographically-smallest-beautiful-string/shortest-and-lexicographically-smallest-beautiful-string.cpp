class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        vector<int> a(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                count++;
            }
            a[i + 1] = count;
        }
        int len = n + 1;
        for (int i = 0; i <= n; i++) {
            if (a[i] >= k) {
                int j = i;
                while (a[j] != a[i] - k) {
                    j--;
                }
                len = min(len, i - j);
            }
        }

        if (len == n + 1) {
            return "";
        }

        vector<string> ans;
        for (int i = 0; i <= n - len; i++) {
            int one = 0;
            string t = "";
            for (int j = i; j < i + len; j++) {
                if (s[j] == '1') {
                    one++;
                }
                t += s[j];
            }
            if (one == k) {
                ans.push_back(t);
            }
        }

        int m = ans.size();
        string result = ans[0];
        for (int i = 1; i < m; i++) {
            string t = ans[i];
            int j = 0;
            while (j < len) {
                if (result[j] > t[j]) {
                    result = t;
                    break;
                } else if (result[j] < t[j]) break;
                j++;
            }
        }

        return result;
    }
};