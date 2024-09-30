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
    int ans=INT_MAX;
    void solution(TreeNode* node, int no){
        if(node->left==nullptr && node->right==nullptr) {
            // ans=no;
            if(ans>no)ans=no;
            return;
        }
        if(node->left){
            solution(node->left,no+1);
        }
        if(node->right){
            solution(node->right,no+1);
        }
    }
    int minDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        solution(root,1);
        return ans;
    }
};