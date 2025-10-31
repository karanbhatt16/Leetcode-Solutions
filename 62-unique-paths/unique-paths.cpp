class Solution {
public:
    int uniquePaths(int m, int n){
        vector<int> dp(n,0);
        dp[0]=1;
        vector<int> temp(n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(j>0){
                    temp[j]=dp[j]+temp[j-1];
                }else{
                    temp[j]=dp[j];
                }
                dp[j]=temp[j];
            }
        }
        return dp[n-1];
    }
};