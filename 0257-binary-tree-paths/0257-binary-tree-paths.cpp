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
    vector<string> arr;
    void preorder(TreeNode* node,string a){
        if(node==nullptr) return ;
        a=a+"->"+to_string(node->val);
        if(node->left==nullptr &&node->right==nullptr) arr.push_back(a);
        preorder(node->left,a);
        preorder(node->right,a);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr) return arr;
        string a=to_string(root->val);
        if(root->left==nullptr&&root->right==nullptr) {
        arr.push_back(a);
            return arr;
        }
        preorder(root->left,a);
        preorder(root->right,a);
        return arr;
    }
};