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
    bool yes=false;
    void answer(TreeNode* node, int val,int target){
        if(node==nullptr){
            // if(val==target) {
                // yes=true;
                return;
            // }
        }
        val+=node->val;
        if(node->left==nullptr && node->right==nullptr && val==target){
            yes=true;
            return;
        }
            answer(node->left, val,target);
            answer(node->right,val,target);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        if(root->left==nullptr && root->right==nullptr && root->val==targetSum) return true;
        answer(root,0,targetSum);
        return yes;
    }
};