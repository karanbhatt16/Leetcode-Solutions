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
    vector<vector<int>> result;
    void solve(TreeNode* root, int targetSum, vector<int>& ans){
        if(root == NULL){
            ans.push_back(0);
            return;
        }
        targetSum=targetSum-root->val;
        ans.push_back(root->val);
        if(root->left == NULL && root->right == NULL){
            if(targetSum==0){
                result.push_back(ans);
            }
            return;
        }
        solve(root->left, targetSum, ans);
        ans.pop_back();
        solve(root->right, targetSum, ans);
        ans.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> ans;
        solve(root, targetSum, ans);
        return result;
    }
};