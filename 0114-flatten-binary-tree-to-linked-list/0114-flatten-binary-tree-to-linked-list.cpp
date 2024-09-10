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
vector<TreeNode*> arr;
    void preorder(TreeNode* node){
        if(node==nullptr) return;
        arr.push_back(node);
        preorder(node->left);
        preorder(node->right);

    }
    void flatten(TreeNode* root) {
        TreeNode* node=root;
        preorder(node);
        for(int i=1;i<arr.size();i++){
            // TreeNode*mover=new TreeNode(arr[i]);
            node->right=arr[i];
            node->left=nullptr;
            node=node->right;
        }
        
    }
};