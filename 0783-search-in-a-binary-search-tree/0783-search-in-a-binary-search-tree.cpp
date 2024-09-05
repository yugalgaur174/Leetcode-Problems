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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==nullptr) return nullptr;
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* found=nullptr;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==val){
                found=node;
                break;
            }
            if(node->left!=nullptr) {
                q.push(node->left);
            }
            if(node->right!=nullptr) q.push(node->right);
        }
        return found;
    }
};