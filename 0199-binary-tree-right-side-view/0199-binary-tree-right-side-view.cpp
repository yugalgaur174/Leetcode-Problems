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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        if(root==nullptr) return arr;
        queue<pair<TreeNode*,int>> q;
        q.push(make_pair(root,0));
        map<int,int>mpp;
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* node=it.first;
            int levelno=it.second;
            mpp[levelno]=node->val;
            if(node->left!=nullptr){
                q.push(make_pair(node->left,levelno+1));
            }
            if(node->right!=nullptr){
                q.push(make_pair(node->right,levelno+1));
            }
        } 
        for(auto it:mpp){
            arr.push_back(it.second);
        }
        return arr;
    }
};