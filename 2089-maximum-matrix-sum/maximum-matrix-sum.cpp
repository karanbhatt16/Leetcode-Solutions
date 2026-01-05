class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int count=0;
        long long ans=0;
        int zero=0;
        int min=INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0) zero++;
                if(matrix[i][j]<0){
                    count++;
                }
                if(min>abs(matrix[i][j])){
                    min=abs(matrix[i][j]);
                }
                ans+=abs(matrix[i][j]);
            }
        }
        if(count%2==0) return ans;
        else if(zero) return ans;
        else return ans=ans-2*min;
    }
};