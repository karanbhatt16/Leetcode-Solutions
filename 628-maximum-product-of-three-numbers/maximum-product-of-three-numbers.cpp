class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int size=nums.size()-1;
        sort(nums.begin(),nums.end());
        int max1,max2;
        max1=nums[size]*nums[size-1]*nums[size-2];
        max2=nums[0]*nums[1]*nums[size];
        return max1>max2 ? max1 : max2;
    }
};