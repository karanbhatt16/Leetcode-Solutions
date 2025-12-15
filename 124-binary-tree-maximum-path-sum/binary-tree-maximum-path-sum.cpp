/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int solve(TreeNode* root, int &maxi){
        if(root==nullptr) return 0;
        int lf = solve(root->left, maxi);
        int rt = solve(root->right, maxi);
        maxi=max(maxi, lf+rt+root->val);
        if(max(lf,rt)+root->val < 0) return 0;
        return max(lf,rt)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        
        int maxi=INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};