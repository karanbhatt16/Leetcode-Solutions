class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> v;
        for(int i=0;i<nums.size();i++){
            nums[abs(nums[i])-1]=(-1)*abs(nums[abs(nums[i])-1]);
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                v.push_back(i+1);
            }
        }
        return v;
    }
};