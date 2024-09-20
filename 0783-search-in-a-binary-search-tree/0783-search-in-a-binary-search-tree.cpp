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
        TreeNode* mover=root;
        if(mover->val==val) return mover;
        while(mover){
            if(mover->val==val && mover) return mover;
            if(mover->val>val && mover->left){
                mover=mover->left;
            }
            else if(mover->val<val&& mover->right){
               mover=mover->right;

            }
            else{
                return nullptr;
            }
        }
        return root;
    }
};