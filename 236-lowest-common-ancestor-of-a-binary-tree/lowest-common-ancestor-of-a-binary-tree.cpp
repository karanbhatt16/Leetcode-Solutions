/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* &ans){
        if(root==p) return p;
        if(root==q) return q;
        if(root==nullptr) return nullptr;
        TreeNode* left=solve(root->left, p, q, ans);
        TreeNode* right=solve(root->right, p, q, ans);
        if(left==nullptr && right==nullptr) return nullptr;
        else if(left && right) ans=root;
        else if(left) return left;
        else return right;
        return left;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans=nullptr;
        TreeNode* node=solve(root, p, q, ans);
        if(!ans) return node;
        return ans;
    }
};