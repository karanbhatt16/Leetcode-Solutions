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
    void solve(TreeNode* root, int level, int& ans, int&size){
        if(root==NULL) return;
        if(size==level){
            size++;
            ans=root->val;
        }
        solve(root->left, level+1, ans, size);
        solve(root->right, level+1, ans, size);
    }
    int findBottomLeftValue(TreeNode* root) {
        int ans=0, size=0;
        solve(root, 0, ans, size);
        return ans;
    }
};