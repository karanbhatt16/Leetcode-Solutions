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
    long long solve(TreeNode* root, long long sum, long long& maxx){
        if(root==NULL) return 0;
        long long left = solve(root->left, sum, maxx);
        long long right = solve(root->right, sum, maxx);
        long long ans = left+right+root->val;
        maxx = max(maxx, ans*(sum-ans));
        return ans;
    }
    long long summ(TreeNode* root){
        if(root==NULL) return 0;
        return summ(root->left)+summ(root->right)+root->val;
    }
    int maxProduct(TreeNode* root) {
        long long sum=summ(root);
        long long maxx=INT_MIN;
        solve(root, sum, maxx);
        return maxx % 1000000007;
    }
};