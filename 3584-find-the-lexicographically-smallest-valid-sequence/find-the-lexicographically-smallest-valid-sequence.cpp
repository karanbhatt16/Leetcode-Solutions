class Solution {
private:
    vector<int> ans;
    int n, m;
public:
    vector<int> validSequence(string word1, string word2) {
        n = word1.length();
        m = word2.length();
        vector<int> arr(n + 1, 0);
        int i = n - 1;
        int j = m - 1;
        int count = 0;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                count++;
                j--;
            }
            arr[i] = count;
            i--;
        }
        while (i >= 0) {
            arr[i] = count;
            i--;
        }

        i = 0;
        j = 0;
        bool power = true;
        while (i < n && j < m) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                i++;
                j++;
            } else {
                if (arr[i + 1] >= m - j - 1 && power) {
                    ans.push_back(i);
                    power = false;
                    i++;
                    j++;
                } else {
                    i++;
                }
            }
        }
        if (ans.size() != m) {
            return {};
        }
        return ans;
    }
};