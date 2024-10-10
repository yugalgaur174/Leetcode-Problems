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
        int max=0;
        unordered_map<int,int> mpp;
        void traverse(TreeNode* node){
            if(node==nullptr) return;
            mpp[node->val]++;
            if(mpp[node->val]>max) max=mpp[node->val];
            traverse(node->left);
            traverse(node->right);
        }
    vector<int> findMode(TreeNode* root) {
        if(root==nullptr) return arr;
        traverse(root);
        // int max=0;
        for(auto& it:mpp){
            if(it.second==max){
                arr.push_back(it.first);
            }

        }
        return arr;
    }
};