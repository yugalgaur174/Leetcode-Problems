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
    vector<int> a,b;
    void preorder(TreeNode* node,vector<int>&z){
        if(node==nullptr){
            z.push_back(-100000);
            return ;
        }
        z.push_back(node->val);
        preorder(node->left,z);
        preorder(node->right,z);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preorder(p,a);
        preorder(q,b);
        if(a.size()!=b.size()) return false;
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};