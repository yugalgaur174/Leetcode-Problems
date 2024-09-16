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
    void inorder(TreeNode* node, int low, int high){
        if(node==nullptr) return ;
        if(node->val>=low && node->val<=high) ans+=node->val;
        if(node->val>=low) inorder(node->left,low,high);
        inorder(node->right,low,high);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr) return 0;
        inorder(root,low,high);
        
        // queue<TreeNode*> q;
        // q.push(root);
        // int ans=0;
        // while(!q.empty()){
        //     TreeNode* node=q.front();
        //     q.pop();
        //     if(node->val>=low&& node->val<=high){
        //         ans+=node->val;
        //     }
        //     if(node->left!=nullptr )q.push(node->left);
        //     if(node->right!=nullptr)q.push(node->right);
        // }
        return ans;
    }
};