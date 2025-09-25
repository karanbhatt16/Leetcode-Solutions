class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(mat.size()*mat[0].size()!=r*c){
            return mat;
        }
        vector<vector<int>> v(r,vector<int>(c));
        int col=0,row=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(col==c){
                    col=0;
                    row++;
                }
                v[row][col]=mat[i][j];
                col++;
            }
        }
        return v;
    }
};