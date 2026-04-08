class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        long long mod = 1000000007;
        for(int i=0; i< n; i++) {
            int idx = queries[i][0];
            while(idx <= queries[i][1]) {
                long long x = ((long long)nums[idx]*(long long)queries[i][3]) % mod;
                nums[idx] = x;
                idx+= queries[i][2];
            }
        }
        int xorr = 0;
        for(int i=0; i<nums.size(); i++) {
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};