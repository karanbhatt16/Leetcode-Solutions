class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(max>=nums.size()-1) return true;
            if(max<i) return false;
            if(max<i+nums[i]){
                max=i+nums[i];
            }
        }
        return false;
    }
};