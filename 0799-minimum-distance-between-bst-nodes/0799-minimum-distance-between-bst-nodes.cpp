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
    int diff=1000000;
    int prev=-1000000;
    void traverse(TreeNode* node){
        if(node==nullptr) return;
        traverse(node->left);
        int d=abs(node->val-prev);
        if(d<diff)diff=d;
        prev=node->val;
        traverse(node->right);

    }
    int minDiffInBST(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr)) return 0;
        traverse(root);
        return diff;
    }
};