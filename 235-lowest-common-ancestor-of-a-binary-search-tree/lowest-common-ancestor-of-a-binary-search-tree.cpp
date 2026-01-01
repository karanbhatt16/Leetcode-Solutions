/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int start=p->val;
        int end=q->val;
        while(true){
            if(root==NULL) return NULL;
            if(root->val<min(start,end)) root=root->right;
            else if(root->val>max(start,end)) root=root->left;
            else return root;
        }
        return root;
    }
};