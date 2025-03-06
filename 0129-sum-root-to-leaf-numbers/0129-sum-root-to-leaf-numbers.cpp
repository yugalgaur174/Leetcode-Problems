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
    void find(TreeNode* node, int sum){
        if(node==nullptr){
            return;
        }
        if(!node->left && !node->right){
            ans+=sum*10+node->val;
            // cout<<ans<<endl;
            return;
        }
        if(node->left){
            find(node->left,sum*10+node->val);
        }
        if(node->right){
            find(node->right, sum*10+node->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)return 0;
        find(root,0);
        return ans;
        
    }
};