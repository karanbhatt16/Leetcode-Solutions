/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        ans=ans+to_string(root->val)+',';
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    ans=ans+to_string(node->left->val)+',';
                }else{
                    ans=ans+"#,";
                }
                if(node->right){
                    q.push(node->right);
                    ans=ans+to_string(node->right->val)+',';
                }else{
                    ans=ans+"#,";
                }
            }
        }
        ans.pop_back();
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return nullptr;
        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            getline(s, str, ',');
            if(str=="#"){
                node->left=nullptr;
            }else{
                TreeNode* left=new TreeNode(stoi(str));
                node->left=left;
                q.push(left);
            }
            getline(s, str, ',');
            if(str=="#"){
                node->right=nullptr;
            }else{
                TreeNode* right=new TreeNode(stoi(str));
                node->right=right;
                q.push(right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));