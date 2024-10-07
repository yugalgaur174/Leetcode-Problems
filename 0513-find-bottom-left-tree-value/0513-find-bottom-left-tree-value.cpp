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
int lev=0;
    void find(TreeNode* node,int level){
        if(node==nullptr) return;
        if(level>lev){
            ans=node->val;
            lev=level;
        }
        find(node->left,level+1);
        find(node->right,level+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        if(root==nullptr) return 0;
        ans=root->val;
        find(root,0);
        return ans;
    }
};