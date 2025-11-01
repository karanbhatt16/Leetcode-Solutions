class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for(int i=triangle.size()-1;i>=0;i--){
            for(int j=0;j<triangle[i].size()-1;j++){
                if(triangle[i][j]<triangle[i][j+1]){
                    triangle[i-1][j]+=triangle[i][j];
                }else{
                    triangle[i-1][j]+=triangle[i][j+1];
                }
            }
        }
        return triangle[0][0];
    }
};