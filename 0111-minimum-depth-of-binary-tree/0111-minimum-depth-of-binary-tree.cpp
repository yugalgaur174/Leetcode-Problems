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
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
           auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int no=it.second;
            if(node->left==nullptr && node->right==nullptr) {
                return no;
                break;
            }
            if(node->left){
                q.push({node->left,no+1});
            }
            if(node->right){
                q.push({node->right,no+1});
            }
        }
        return 0;
    }
};