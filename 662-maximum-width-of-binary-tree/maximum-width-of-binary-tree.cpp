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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>>q;
        if(root==nullptr) return 0;
        root->val=1;
        q.push({root, 0});
        int width=0;
        while(!q.empty()){
            int size=q.size();
            int start=0,end=0;
            long long mmin=q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                long long index=q.front().second-mmin;
                q.pop();
                if(node->left){
                    q.push({node->left, (index)*2+1});
                }
                if(node->right){
                    q.push({node->right, (index)*2+2});
                }
                if(i==0){
                    start=index;
                }
                if(i==size-1){
                    end=index;
                }
            }
            if(width<(end-start+1)) width=end-start+1;
        }
        return width;
    }
};