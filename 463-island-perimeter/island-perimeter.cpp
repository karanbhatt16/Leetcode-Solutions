class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        int peri=0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]==1){
                    int left,right,top,bottom;
                    left=(j==0)?1:(grid[i][j-1]==0?1:0);
                    right=(j==col-1)?1:(grid[i][j+1]==0?1:0);
                    top=(i==0)?1:(grid[i-1][j]==0?1:0);
                    bottom=(i==row-1)?1:(grid[i+1][j]==0?1:0);
                    peri+=left+right+top+bottom;
                }
            }
        }
        return peri;
    }
};