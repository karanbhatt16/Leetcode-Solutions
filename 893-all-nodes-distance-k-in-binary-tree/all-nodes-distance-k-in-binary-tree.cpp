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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        map<TreeNode*, TreeNode*> mp;
        vector<int> ans;
        if(root==nullptr) return ans;
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
            }
        }
        set<TreeNode*> visited;
        q.push(target);
        visited.insert(target);
        while(!q.empty()){
            if(k==0) break;
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
            k--;  
        }
        int size=q.size();
        for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};