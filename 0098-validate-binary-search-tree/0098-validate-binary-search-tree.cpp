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
    bool valid(TreeNode* node,long long a,long long b){
        if(node==nullptr) return true;
        if(node->val>=b || node->val<=a) return false;
        return valid(node->left,a,node->val) && valid(node->right,node->val,b);
    }
    bool isValidBST(TreeNode* root) {
        // if(!root->left && !root->right) return true;
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};