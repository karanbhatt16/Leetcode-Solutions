class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> mat(matrix.size(), vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                mat[i][j] = (matrix[i][j] - '0');
            }
        }
        int ans = 0;
        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 1 && i != 0){
                    mat[i][j]+=mat[i-1][j];
                }
                if(mat[i][j] != 0){
                    int count;
                    int maxx = 0;
                    for(int l = mat[i][j]; l > 0; l--){
                        count = 0;
                        for(int k = j; k > -1; k--){
                            if(mat[i][k] >= l){
                                count++;
                            }else{
                                break;
                            }
                        }
                        maxx = max(maxx, count*l);
                    }
                    ans = max(maxx, ans);
                }
            }
        }
        return ans;
    }
};