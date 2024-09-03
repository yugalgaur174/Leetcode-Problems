/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
 bool isSameTree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr)
            return true;
        if (s == nullptr || t == nullptr)
            return false;
        if (s->val != t->val)
            return false;
        return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        if (subRoot == nullptr)
            return true;
        if(isSameTree(root,subRoot)){
            return true;
        }
        queue<TreeNode*> q;
        q.push(root);
        TreeNode*a=nullptr;
        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != nullptr) {
                if (isSameTree(node->left, subRoot)) {
                    a = node->left;
                    break;
                }
                q.push(node->left);
            }
            if (node->right != nullptr) {
                if (isSameTree(node->right, subRoot)) {
                    a = node->right;
                    break;
                }
                q.push(node->right);
            }
        }
        if (a != nullptr) {
            return true;
        }
            
        return false;
    }
};