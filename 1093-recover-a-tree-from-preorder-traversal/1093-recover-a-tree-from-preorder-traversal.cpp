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
    int i=0;
    void make(TreeNode* parent, int level, string traversal,int curr){
        if(i==traversal.size())return;
        int cnt=0;
        while(traversal[i]=='-'){
            cnt++;
            i++;
        }
        if(cnt==level){
            int num = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }
            TreeNode* node=new TreeNode(num);
            parent->left=node;
            make(node,level+1,traversal,i);
        }
        else{
            i=curr;
            return;
        }
        curr=i;
        cnt=0;
        while(traversal[i]=='-'){
            cnt++;
            i++;
        }
        if(cnt==level){
            int num = 0;
            while (i < traversal.size() && isdigit(traversal[i])) {
                num = num * 10 + (traversal[i] - '0');
                i++;
            }
            TreeNode* node=new TreeNode(num);
            parent->right=node;
            make(parent->right,level+1,traversal,i);
        }
        else{
            i=curr;
            return;
        }
    }
    TreeNode* recoverFromPreorder(string traversal) {
        if(traversal.size()==0)return nullptr;
        int num = 0;
        // int i = 0;
        while (i < traversal.size() && isdigit(traversal[i])) {
            num = num * 10 + (traversal[i] - '0');
            i++;
        }
        TreeNode* root=new TreeNode(num);
        make(root, 1,traversal,i);
        return root;
    }
};