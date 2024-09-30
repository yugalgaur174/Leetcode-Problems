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

    void traverse(TreeNode*root){
        if(root==nullptr) return;
        traverse(root->left);
        int d=abs(prev-root->val);
        if(d<diff) diff=d;
        prev=root->val;
        traverse(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        if(root==nullptr || (root->left==nullptr && root->right==nullptr)) return 0;
        traverse( root);
        return diff;
    }
};