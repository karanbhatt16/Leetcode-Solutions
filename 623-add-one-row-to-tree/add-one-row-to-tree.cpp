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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node= new TreeNode(val);
            node->left=root;
            return node;
        }
        queue<TreeNode*> q;
        depth--;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(depth==1){
                    TreeNode* x=new TreeNode(val);
                    x->left=node->left;
                    node->left=x;
                    TreeNode* y=new TreeNode(val);
                    y->right=node->right;
                    node->right=y;
                    continue;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            depth--;
        }
        return root;
    }
};