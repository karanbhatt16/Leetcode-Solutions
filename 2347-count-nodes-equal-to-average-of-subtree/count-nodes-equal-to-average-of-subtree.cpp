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

struct info {
    int sum;
    int nodes;
};

class Solution {
private:
    int ans = 0;
    info solve(TreeNode* root) {
        if (root == NULL) {
            info newInfo;
            newInfo.sum = 0;
            newInfo.nodes = 0;
            return newInfo;
        }
        info left = solve(root->left);
        info right = solve(root->right);
        info result;
        result.sum = left.sum + right.sum + root->val;
        result.nodes = left.nodes + right.nodes + 1;
        if (root->val == (result.sum) / result.nodes) {
            ans++;
        }
        return result;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return ans;
    }
};