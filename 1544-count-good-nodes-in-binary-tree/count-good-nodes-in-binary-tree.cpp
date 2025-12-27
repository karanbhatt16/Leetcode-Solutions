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
    int solve(TreeNode* root, int m){
        if(root==nullptr) return 0;
        if(root->left==nullptr && root->right==nullptr){
            if(root->val>=m) return 1;
            else return 0;
        }
        int ans=solve(root->left, max(m,root->val))+solve(root->right, max(m,root->val));
        if(root->val>=m) ans+=1;
        return ans;
    }
    int goodNodes(TreeNode* root) {
        return solve(root, root->val);
    }
};