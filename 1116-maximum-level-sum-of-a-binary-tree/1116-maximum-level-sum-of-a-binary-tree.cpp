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

    int maxLevelSum(TreeNode* root) {
        // if(root==nullptr) return -1;
        // return 0;
        queue<TreeNode*> q;
        int max=root->val;
        int maxlevel=1;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            level++;
            for(int i=0;i<size;i++){
            TreeNode* node=q.front();
            q.pop();
                if(node->left) q.push(node->left);
                if(node->right)q.push(node->right);
                sum+=node->val;

            }
            if(sum>max){
                max=sum;
                maxlevel=level;
            }
        }
        return maxlevel;
    }
};