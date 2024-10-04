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
    int sum=0;
    void ans(TreeNode* node,bool left){
        if(node==nullptr) return ;
        if(!node->left && !node->right && left){
            sum+=node->val;
        }
        ans(node->left,true);
        ans(node->right,false);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        // bool left=false;
        ans(root,false);
        return sum;
    }
};