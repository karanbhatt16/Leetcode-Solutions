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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> q;
        q.push(root);
        vector<TreeNode*> temp;
        while(!q.empty()){
            int size = q.size();
            temp.clear();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    mp[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    mp[node->right] = node;
                }
                temp.push_back(node);
            }
        }
        while(true){
            if(temp[0] == temp[temp.size()-1]){
                break;
            }
            temp[0] = mp[temp[0]];
            temp[temp.size()-1] = mp[temp[temp.size()-1]];
        }
        return temp[0];
    }
};