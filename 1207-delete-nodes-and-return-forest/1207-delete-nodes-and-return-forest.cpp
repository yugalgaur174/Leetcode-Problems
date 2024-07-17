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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
         unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        if (root && to_delete_set.find(root->val) == to_delete_set.end()) {
            forest.push_back(root);
        }
        delNodesHelper(root, to_delete_set, forest);
        return forest;
    }
private:
    TreeNode* delNodesHelper(TreeNode* node, unordered_set<int>& to_delete_set, vector<TreeNode*>& forest) {
        if (!node) return nullptr;
        node->left = delNodesHelper(node->left, to_delete_set, forest);
        node->right = delNodesHelper(node->right, to_delete_set, forest);
        if (to_delete_set.find(node->val) != to_delete_set.end()) {
            if (node->left) forest.push_back(node->left);
            if (node->right) forest.push_back(node->right);
            return nullptr;
        }
        return node;
    }
};