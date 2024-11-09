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
    void set(TreeNode* root, int val, int depth, int level){
        if(root==nullptr){
            return;
        }
        if(level==depth-1){
            TreeNode * node1= new TreeNode(val);
            TreeNode * node2= new TreeNode(val);
            if(root->left!=nullptr){

            node1->left=root->left;
            }
            root->left=node1;
            if(root->right!=nullptr){

            node2->right=root->right;
            }
            root->right=node2;
            return;
        }
        set(root->left,val, depth, level+1);
        set(root->right, val, depth, level+1);

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* node=new TreeNode(val);
            node->left=root;
            return node;
        }
        set(root,val, depth, 1 );

        return root;
    }
};