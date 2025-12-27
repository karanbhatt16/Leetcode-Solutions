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
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*> q;
        map<TreeNode*, TreeNode*> mp;
        TreeNode* target=nullptr;
        if(root==nullptr) return 0;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    mp[node->left]=node;
                }
                if(node->right){
                    q.push(node->right);
                    mp[node->right]=node;
                }
                if(node->val==start) target=node;
            }
        }
        set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        int count=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(mp[node] && visited.find(mp[node])==visited.end()){
                    q.push(mp[node]);
                    visited.insert(mp[node]);
                }
                if(node->left && visited.find(node->left)==visited.end()){
                    q.push(node->left);
                    visited.insert(node->left);
                }
                if(node->right && visited.find(node->right)==visited.end()){
                    q.push(node->right);
                    visited.insert(node->right);
                }
            }
            count++;
        }
        return count-1;
    }
};