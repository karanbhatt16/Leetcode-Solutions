class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i=m-1;i>=0;i--){
            dp[n][i] = dp[n][i+1] + s2[i];
        }
        for(int i=n-1;i>=0;i--){
            dp[i][m] = dp[i+1][m] + s1[i];
        }
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(s1[i]==s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }else{
                    dp[i][j] = min({dp[i+1][j]+s1[i], dp[i][j+1]+s2[j]});
                }
            }
        }
        return dp[0][0];
    }
};
