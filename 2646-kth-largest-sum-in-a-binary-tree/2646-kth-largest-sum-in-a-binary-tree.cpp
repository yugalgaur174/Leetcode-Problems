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
    // unordered_map<int, long long> mpp;
    
        vector<long long> ans;
    void check(TreeNode* node, int level){
        if(node==nullptr) return ;
        if(ans.size()<level){
            ans.push_back(node->val);
        }
        else{
            ans[level-1]+=node->val;
        }
        check(node->left,level+1);
        check(node->right, level+1);
    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root==nullptr) return 0;
        check(root,1);
        
        sort(ans.begin(),ans.end());
        if(k>ans.size()) return -1;
        return ans[ans.size()-k];
    }
};