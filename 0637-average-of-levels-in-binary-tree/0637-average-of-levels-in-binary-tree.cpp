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
    vector<double> ans;
    vector<int> levelno;
    void set(TreeNode* node, int level){
        if(node==nullptr){
            return;
        }
        if(level==ans.size()){
            levelno.push_back(1);
            ans.push_back(double(node->val));

        }
        else{
            levelno[level]++;
            ans[level]+=node->val;
        }
        set(node->left, level+1);
        set(node->right, level+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        if(root==nullptr){
            return ans;
        }
        set(root, 0);
        for(int i=0;i<ans.size();i++){
            ans[i]=ans[i]/double(levelno[i]);
        }
        return ans;

    }
};