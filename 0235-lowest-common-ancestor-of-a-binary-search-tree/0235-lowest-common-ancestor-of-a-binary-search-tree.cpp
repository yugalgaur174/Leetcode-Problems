/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==nullptr|| q==nullptr) return nullptr;
        if(root->val<p->val && root->val<q->val){
           return lowestCommonAncestor(root->right,p,q);
        }
        else if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        else if((root->val<p->val && root->val>q->val)||(root->val>p->val && root->val<q->val)){
            return root;
        }
        else if((root->val==p->val && root->val>q->val)|| (root->val==p->val && root->val<q->val)){
            return p;
        }
        else if((root->val>p->val && root->val==q->val)|| (root->val<p->val && root->val==q->val)){
            return q;
        }
        return nullptr;
    }
};
// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//  * };
//  */

// class Solution {
// public:
//     vector<TreeNode*> a1;
//     vector<TreeNode*> a2;
//     void path(TreeNode* node,TreeNode*p,vector<TreeNode*>& a){
//         if(node==nullptr) return;
//         if(node==p){
//             a.push_back(node);
//             return;
//         }
//         else{
//             a.push_back(node);
//             if(node->val>p->val){
//                 path(node->left,p,a);
//             }
//             else{
//                 path(node->right,p,a);
//             }
//         }
//     }
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if(p==nullptr || q==nullptr) return nullptr;
//         path(root,p,a1);
//         path(root,q,a2);
//         TreeNode* ans=nullptr;
//         if(a1.size()<=a2.size()){
//             for(int i=0;i<a1.size();i++){
//                 if(find(a2.begin(),a2.end(),a1[i])!=a2.end()){
//                     ans=a1[i];
//                 }
//             }
//         }
//         else{
//             for(int i=0;i<a2.size();i++){
//                 if(find(a1.begin(),a1.end(),a2[i])!=a1.end()){
//                     ans=a2[i];
//                 }
//             }
//         }
//         return ans;
//     }
// };