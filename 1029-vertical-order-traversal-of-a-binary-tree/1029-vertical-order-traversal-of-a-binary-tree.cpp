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
    unordered_map<int,vector<pair<int,int>>> mpp;

    int minz=0;
    int maxz=0;
    void inorder(TreeNode* node,int z,int y){
        if(node==nullptr) return;
        if(minz>z){
            minz=z;
        }
        if(maxz<z){
            maxz=z;
        }
        inorder(node->left,z-1,y+1);
        mpp[z].push_back(make_pair(y,node->val));
        inorder(node->right,z+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        inorder(root,0,0);
        vector<vector<int>> arr;
        for(int i=minz;i<=maxz;i++){
            vector<pair<int,int>> temp=mpp[i];
            sort(temp.begin(),temp.end());
            vector<int> val;
            for(auto& p:temp){
                val.push_back(p.second);
            }
            arr.push_back(val);
        }
        return arr;
    }
};