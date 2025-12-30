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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node=root;
        while(node){
            if(node->val>val){
                if(!node->left){
                    node->left=new TreeNode(val);
                    return root;
                }
                node=node->left;
            }else{
                if(!node->right){
                    node->right=new TreeNode(val);
                    return root;
                }
                node=node->right;
            }
        }
        return new TreeNode(val);
    }
};