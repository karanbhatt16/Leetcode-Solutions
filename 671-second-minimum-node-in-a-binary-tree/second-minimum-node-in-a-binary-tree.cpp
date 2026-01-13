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
    long long minimum = LLONG_MAX;
    long long second_minimum = LLONG_MAX;
    void solve(TreeNode* root){
        if(root == NULL){
            return ;
        }
        if(root->val < minimum){
            second_minimum = minimum;
            minimum = root->val;
        }
        if(root->val < second_minimum && root->val > minimum){
            second_minimum = root->val;
        }
        solve(root->left);
        solve(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        solve(root);
        if(second_minimum == LLONG_MAX) return -1;
        return second_minimum;
    }
};