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
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ans=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val>=low&& node->val<=high){
                ans+=node->val;
            }
            if(node->left!=nullptr&& node->val>low )q.push(node->left);
            if(node->right!=nullptr&& node->val<high)q.push(node->right);
        }
        return ans;
    }
};