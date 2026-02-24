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
    int solve(TreeNode* root, int num) {
        if (root == nullptr) return 0;
        num = num * 2 + root->val;
        if (root->left == nullptr && root->right == nullptr) return num;
        int left = solve(root->left, num);
        int right = solve(root->right, num);
        return left + right;
    }
    int sumRootToLeaf(TreeNode* root) {
        return solve(root, 0);
    }
};