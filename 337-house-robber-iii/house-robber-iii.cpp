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
    map<pair<TreeNode*, bool>, int> mp;
    int solve(TreeNode* root, bool is_root){
        if(root == NULL) return 0;
        if(mp.find({root, is_root}) != mp.end()){
            return mp[{root, is_root}];
        }
        int a = solve(root->left, true);
        int b = solve(root->right, true);
        int c = solve(root->left, false);
        int d = solve(root->right, false);
        if(!is_root) return mp[{root, is_root}] = max({a+b, a+d, b+c, c+d});
        return mp[{root, is_root}] = max({a+b, a+d, b+c, c+d+root->val});
    }
    int rob(TreeNode* root) {
        return solve(root, true);
    }
};