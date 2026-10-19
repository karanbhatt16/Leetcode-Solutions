class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int m = 1 << n;
        for (int i = 0; i < m; i++) {
            ans.push_back(i ^ (i >> 1));
        }
        vector<int> result;
        result.push_back(0);
        for (int i = 0; i < m - 1 ; i++) {
            ans[i] = ans[i] ^ ans[i + 1];
            result.push_back(result.back() ^ ans[i]);
        }
        return result;
    }
};