class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(i<k){
                if(nums[i]>nums[i+k]){
                    sum+=nums[i];
                }
            }else if(i+k>=nums.size()){
                if(nums[i]>nums[i-k]){
                    sum+=nums[i];
                }
            }else{
                if(nums[i]>nums[i-k] && nums[i]>nums[i+k]){
                    sum+=nums[i];
                }
            }
        }
        return sum;
    }
};