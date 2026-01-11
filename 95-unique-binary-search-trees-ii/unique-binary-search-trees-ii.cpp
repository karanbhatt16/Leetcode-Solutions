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
    vector<TreeNode*> solve(int start, int end){
        if(start > end) return {NULL};
        if(start == end) return {new TreeNode(start)};
        vector<TreeNode*> result;
        for(int i = start; i <= end; i++){
            vector<TreeNode*> left_bsts = solve(start, i-1);
            vector<TreeNode*> right_bsts = solve(i+1, end);
            for(TreeNode* left_root : left_bsts){
                for(TreeNode* right_root : right_bsts){
                    TreeNode* root = new TreeNode(i);
                    root->left = left_root;
                    root->right = right_root;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
    vector<TreeNode*> generateTrees(int n) {
        return solve(1, n);
    }
};