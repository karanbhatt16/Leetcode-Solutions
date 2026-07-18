class Solution {
public:
    int gcd(int num1,int num2){
        while (num2 != 0) {
            int temp = num1;
            num1 = num2;
            num2 = temp % num2;
        }
        return num1;
    }
    int findGCD(vector<int>& nums) {
        int max=1;
        int min=1000;
        int size=nums.size();
        for(int i=0;i<size;i++){
            if(max<nums[i]) max=nums[i];
            if(min>nums[i]) min=nums[i];
        }
        return gcd(max,min);
    }
};