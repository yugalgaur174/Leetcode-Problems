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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==nullptr){
            TreeNode* node=new TreeNode(val);
            return node;
        }
        TreeNode* mark=root;
        TreeNode* head=root;
        while(root){
            if(root->val<val){
                mark=root;
                root=root->right;
            }
            else{
                mark=root;
                root=root->left;
            }
            if(root==nullptr){
                    TreeNode* node=new TreeNode(val);
                if(mark->val>val){
                    mark->left=node;
                }
                else{
                    mark->right=node;
                }
                break;
            }
            
        }

        return head;
    }
};