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
    int m=0;
    int ans;
    void inorder(TreeNode* node,int k){
        if(node==nullptr) {
            // m++;
            // if(m==k) ans=m;
            return;
        }
        inorder(node->left,k);
        m++;
        if(m==k) {
            ans=node->val;
            return;
        }
        inorder(node->right,k);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ans;
    }
};