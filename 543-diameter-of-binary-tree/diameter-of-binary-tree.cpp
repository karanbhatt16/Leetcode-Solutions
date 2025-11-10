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
    int solve(TreeNode* root, int& diameter){
        if(root==nullptr) return 0;
        int lf=solve(root->left, diameter);
        int rt=solve(root->right, diameter);
        if(diameter<lf+rt){
            diameter=lf+rt;
        }
        return 1+max(lf, rt);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter=0;
        solve(root, diameter);
        return diameter;
    }
};