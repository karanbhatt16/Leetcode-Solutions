class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int idx1,idx2;
        idx1=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[idx1]){
                idx1=i;
            }
        }
        idx2=(idx1==nums.size()-1)?idx1-1:idx1+1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[idx2] && idx1!=i){
                idx2=i;
            }
        }
        return (nums[idx1]-1)*(nums[idx2]-1);
    }
};