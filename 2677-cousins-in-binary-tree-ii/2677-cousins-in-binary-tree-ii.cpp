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
    vector<int> arr;
    void check(TreeNode* node, int level){
        if(node==nullptr) return;
        if(arr.size()<level){
            arr.push_back(node->val);
        }
        else{
            arr[level-1]+=node->val;
        }
        check(node->left,level+1);
        check(node->right,level+1);
    }
    void modify(TreeNode* node, int level){
        int left,right;
        if(node->left){
            left=node->left->val;
        }
        else{
            left=0;
        }
        if(node->right){
            right=node->right->val;
        }
        else{
            right=0;
        }
        int ans=left+right;
        level++;
        if(node->left){
            node->left->val=arr[level]-ans;
            modify(node->left,level);
        }
        if(node->right){
            node->right->val=arr[level]-ans;
            modify(node->right,level);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        root->val=0;
        check(root,1);
        modify(root,0);
        return root;
    }
};