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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        unordered_set<int> s;

        int n = descriptions.size();

        for (int i = 0; i < n; i++) {
            if (descriptions[i][2] == 1) {
                left[descriptions[i][0]] = descriptions[i][1];
            } else {
                right[descriptions[i][0]] = descriptions[i][1];
            }
            s.insert(descriptions[i][1]);
        }

        int rootval;
        
        for (int i = 0; i < n; i++) {
            if (s.find(descriptions[i][0]) == s.end()) {
                rootval = descriptions[i][0];
                break;
            }
        }

        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(rootval);
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (left[node->val] > 0) {
                TreeNode* leftnode = new TreeNode(left[node->val]);
                node->left = leftnode;
                q.push(leftnode);
            }
            if (right[node->val] > 0) {
                TreeNode* rightnode = new TreeNode(right[node->val]);
                node->right = rightnode;
                q.push(rightnode);
            }
        }

        return root;

    }
};