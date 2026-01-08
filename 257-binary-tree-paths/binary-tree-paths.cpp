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
    void solve(TreeNode* root, vector<string>& ans, string temp){
        if(root==NULL) return;
        temp=temp + to_string(root->val) + "->";
        if(root->left==NULL && root->right==NULL){
            temp.erase(temp.size()-2);
            ans.push_back(temp);
            return;
        }
        solve(root->left, ans, temp);
        solve(root->right, ans, temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string temp;
        solve(root, ans, temp);
        return ans;
    }
};