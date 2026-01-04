class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int count=0;
            int ans=0;
            for(int j=2;j<nums[i];j++){
                if(j>nums[i]/j || count>2){
                    break;
                }
                if(nums[i]%j==0){
                    if(nums[i]!=j*j){
                        count+=2;
                        ans=ans+nums[i]+j+1+(nums[i]/j);
                    }
                    else count+=1;
                }
            }
            if(count==2){
                sum+=ans;
            }
        }
        return sum;
    }
};