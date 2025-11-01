class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                int up=INT_MAX,left=INT_MAX;
                if(i==0 && j==0) continue;
                if(i>0) up=grid[i-1][j];
                if(j>0) left=grid[i][j-1];
                if(up<left) grid[i][j]=up+grid[i][j];
                else grid[i][j]=left+grid[i][j];
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
    }
};