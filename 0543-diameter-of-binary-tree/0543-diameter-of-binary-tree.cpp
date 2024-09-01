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
int maxx=0;
    int diameterOfBinaryTree(TreeNode* root) {
        check(root);
        return maxx;
    }
    int check(TreeNode* node){
        if(node==nullptr) return 0;
        int lh=check(node->left);
        int rh=check(node->right);
        
        int a=abs(lh+rh);
        if(a>maxx){
            maxx=a;
        }
        return max(lh,rh)+1;
    }
};