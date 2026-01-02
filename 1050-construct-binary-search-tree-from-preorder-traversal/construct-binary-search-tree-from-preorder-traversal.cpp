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
    int find_index(vector<int>preorder, int start, int end){
        int ele=preorder[start];
        int index=start;
        for(int i=start; i<=end;i++){
            if(preorder[i]<=ele) index=i;
            else break;
        }
        return index;
    }
    TreeNode* solve(vector<int>& preorder, int start, int end){
        if(start>end){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[start]);
        int index=find_index(preorder, start, end);
        root->left=solve(preorder, start+1, index);
        root->right=solve(preorder, index+1, end);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode* root=new TreeNode(preorder[0]);
        int index=find_index(preorder, 0, preorder.size()-1);
        root->left=solve(preorder, 1, index);
        root->right=solve(preorder, index+1, preorder.size()-1);
        return root;
    }
};