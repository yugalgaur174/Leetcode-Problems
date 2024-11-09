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
    string ans="";
    void postorder(TreeNode* node){
        if(node==nullptr){
            return;
        }
        ans+=to_string(node->val);
        if(node->left){
            ans+="(";
            postorder(node->left);
            ans+=")";
        }
        if(node->right){
            if(!node->left){
                ans+="()";
            }
            ans+="(";
            postorder(node->right);
            ans+=")";
        }
    }
    string tree2str(TreeNode* root) {
        postorder(root);
        return ans;
    }
};