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
    TreeNode* buildTree(const vector<int>& preorder, const vector<int>& inorder) {
        if(preorder.size()==0) return nullptr;
        TreeNode* root=new TreeNode(preorder[0]);
        int i=0;
        while(inorder[i]!=preorder[0]){
            i++;
        }
        root->left = buildTree(
            vector<int>(preorder.begin()+1, preorder.begin() + i+1),
            vector<int>(inorder.begin(), inorder.begin() + i)
        );
        root->right=buildTree(
            vector<int>(preorder.begin()+1+i, preorder.end()),
            vector<int>(inorder.begin()+i+1,inorder.end())
        );
        return root;
    }
};