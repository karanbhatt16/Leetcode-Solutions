class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int candidate=nums[0];
        int score=0;
        for(int i=0;i<nums.size()-4;i++){
            if(nums[i]==candidate) score++;
            else{
                score--;
                if(score<0){
                    candidate=nums[i];
                    score=1;
                }
            }
        }
        if(score>0){
            return candidate;
        }
        for(int i=nums.size()-4; i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    return nums[i];
                }
            }
        }
        return candidate;
    }
};