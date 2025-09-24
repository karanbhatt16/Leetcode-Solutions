class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int max=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max){
                max=nums[i];
            }
        }
        return max*k+(k-1)*k/2;
    }
};