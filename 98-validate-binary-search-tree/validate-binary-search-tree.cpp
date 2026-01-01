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
 #include <climits>
class Solution {
public:
    bool solve(TreeNode* root, long& ele){
        if(root==NULL) return true;
        if(!solve(root->left, ele)) return false;
        if(root->val<=ele){
            return false;
        }
        ele=root->val;
        if(!solve(root->right, ele)) return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long ele=LONG_MIN;
        return solve(root, ele);
    }
};