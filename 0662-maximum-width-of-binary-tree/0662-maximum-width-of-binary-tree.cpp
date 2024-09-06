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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 1;
        queue<pair<TreeNode*,pair<int,unsigned long long>>>q;
        q.push(make_pair(root,make_pair(0,1)));
        map<int,pair<unsigned long long,unsigned long long>>mpp;
        while(!q.empty()){
            auto it=q.front();
            TreeNode* node=it.first;
            int level=it.second.first;
            unsigned long long value=it.second.second;
            q.pop();
            if(mpp.find(level)==mpp.end()) mpp[level]=make_pair(value,value);
            else {
                mpp[level].first = min(mpp[level].first, value);
                mpp[level].second = max(mpp[level].second, value);
            }
            if(node->left!=nullptr){
                // if(mpp[level].first<value){
                //     mpp[level].first=value;
                // }
                // else if(mpp[level].second>value){
                //     mpp[level].second=value;
                // }
                q.push(make_pair(node->left,make_pair(level+1,2*value)));
            }
            if(node->right!=nullptr){
                // if(mpp[level].first<value){
                //     mpp[level].first=value;
                // }
                // else if(mpp[level].second>value){
                //     mpp[level].second=value;
                // }
                q.push(make_pair(node->right,make_pair(level+1,2*value+1)));
            }
        }
        int a=1;
        for(auto it:mpp){
            unsigned long long k = (it.second.second - it.second.first+1);
            a=max(a,static_cast<int>(k));
        }
        return a;
    }
};