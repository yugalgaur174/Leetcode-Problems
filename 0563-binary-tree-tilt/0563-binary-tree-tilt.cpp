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
    int ans=0;
   void sum(TreeNode* node){
    if(node==nullptr) return;
    ans+=node->val;
    sum(node->left);
    sum(node->right);
   }
    int add(TreeNode* node){
        if(node==nullptr) return 0;
        return node->val+add(node->left)+add(node->right);
        
    }
    void tile(TreeNode* node){
        if(node==nullptr) return ;
        int left=add(node->left);
        int right=add(node->right);
        tile(node->left);
        tile(node->right);
        node->val=abs(left-right);
    }

    int findTilt(TreeNode* root) {
        tile(root);
        sum(root);
        return ans;
    }
};