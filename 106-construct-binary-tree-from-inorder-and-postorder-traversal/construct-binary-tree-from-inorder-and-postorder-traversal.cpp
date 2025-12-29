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
    TreeNode* solve(vector<int>& postorder, vector<int>& inorder, int poststart, int postend, int instart, int inend, map<int, int>& mp){
        if(poststart>postend || instart>inend) return nullptr;
        TreeNode* root=new TreeNode(postorder[postend]);
        int inroot=mp[postorder[postend]];
        int left=inroot-instart;
        root->left=solve(postorder, inorder, poststart, poststart+left-1, instart, inroot-1, mp);
        root->right=solve(postorder, inorder, poststart+left, postend-1, inroot+1, inend, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        return solve(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1, mp);
    }
};