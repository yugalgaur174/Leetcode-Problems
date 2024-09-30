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
    int a=0;
    void traverse(TreeNode* node){
        if(node==nullptr) return;
        traverse(node->right);
        a+=node->val;
        node->val=a;
        traverse(node->left);

    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==nullptr) return nullptr;
        traverse(root);
        return root;
    }
};