class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans(2,0);
        for(int i=0;i<mat.size();i++){
            int one = 0;
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    one++;
                }
            }
            if(ans[1]<one){
                ans[1]=one;
                ans[0]=i;
            }
        }
        return ans;
    }
};