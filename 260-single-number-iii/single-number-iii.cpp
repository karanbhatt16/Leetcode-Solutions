class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr=0;
        for(int i=0;i<nums.size();i++){
            xorr=xorr^nums[i];
        }
        if(xorr!=-2147483648) xorr=xorr^(xorr&(xorr-1));
        vector<int>ans(2,0);
        for(int i=0;i<nums.size();i++){
            if(xorr&nums[i]) ans[0]=ans[0]^nums[i];
            else ans[1]=ans[1]^nums[i];
        }
        return ans;
    }
};