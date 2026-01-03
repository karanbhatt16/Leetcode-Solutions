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
    int heightLeft(TreeNode* root){
        int height=0;
        while(root){
            root=root->left;
            height+=1;
        }
        return height;
    }
    int heightRight(TreeNode* root){
        int height=0;
        while(root){
            root=root->right;
            height+=1;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int left = heightLeft(root->left);
        int right = heightRight(root->right);
        if(left == right){
            return (2<<left)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};