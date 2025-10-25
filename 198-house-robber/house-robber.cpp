class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=0,prev2=0;
        int price;
        for(int i=0;i<nums.size();i++){
            int rob= nums[i]+prev2;
            price=max(prev1,rob);
            prev2=prev1;
            prev1=price;
        }
        return price;
    }
};