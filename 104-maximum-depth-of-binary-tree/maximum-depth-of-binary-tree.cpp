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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int size=1,temp=0;
        int count=0;
        while(!q.empty()){
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->right!=nullptr){
                    q.push(node->right);
                    temp++;
                }
                if(node->left!=nullptr){
                    q.push(node->left);
                    temp++;
                }
            }
            size=temp;
            temp=0;
            count++;
        }
        return count;
    }
};