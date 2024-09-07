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
    void markparents(TreeNode* root,
                     unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left != nullptr) {
                parent_track[node->left] = node;
                q.push(node->left);
            }
            if (node->right != nullptr) {
                parent_track[node->right] = node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> arr;
        if (root == nullptr)
            return arr;
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markparents(root, parent_track);
        int level = 0;
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;
        while (!q.empty()) {
            int n = q.size();
            if (level == k)
                break;
            level++;
            for (int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();
                if (node->left != nullptr && visited[node->left] == false) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right != nullptr && visited[node->right] == false) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (parent_track[node] &&
                    visited[parent_track[node]] == false) {
                    q.push(parent_track[node]);
                    visited[parent_track[node]] = true;
                }
            }
        }
        while (!q.empty()) {
            arr.push_back(q.front()->val);
            q.pop();
        }
        return arr;
    }
};