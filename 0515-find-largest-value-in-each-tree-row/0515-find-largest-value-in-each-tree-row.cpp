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
    vector<int> ans;
    void find(TreeNode* node, int level){
        if(node==nullptr)return;
        if(ans.size()==level){
            ans.push_back(node->val);
        }
        else{
            if(ans[level]<node->val){
                ans[level]=node->val;
            }
        }
        find(node->left,level+1);
        find(node->right, level+1);
    }
    vector<int> largestValues(TreeNode* root) {
        if(root==nullptr)return ans;
        find(root, 0);
        return ans;
    }
};