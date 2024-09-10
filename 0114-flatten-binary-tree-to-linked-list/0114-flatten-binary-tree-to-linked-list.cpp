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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        TreeNode* curr=root;
        while(curr!=nullptr){
            if(curr->left!=nullptr){
                TreeNode * prev=curr->left;
                while(prev->right!=nullptr){
                    prev=prev->right;
                }
                prev->right=curr->right;
                curr->right=curr->left;
                curr->left=nullptr;
            }
            curr=curr->right;
        }
    }
};

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//         if(root==nullptr) return ;
//         stack<TreeNode*> st;
//         st.push(root);
//         while(!st.empty()){
//             TreeNode* curr=st.top();
//             st.pop();
//             if(curr->right!=nullptr) st.push(curr->right);
//             if(curr->left!=nullptr) st.push(curr->left);
//             if(!st.empty()) curr->right=st.top();
//             curr->left=nullptr;
//         }
//     }
// };

// class Solution {
// public:
//     TreeNode* node=nullptr;
//     void flatten(TreeNode* root) {
//         if(root==nullptr) return;
//         flatten(root->right);
//         flatten(root->left);
//         root->right=node;
//         root->left=nullptr;
//         node=root;
//     }
// };

// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
// vector<TreeNode*> arr;
//     void preorder(TreeNode* node){
//         if(node==nullptr) return;
//         arr.push_back(node);
//         preorder(node->left);
//         preorder(node->right);

//     }
//     void flatten(TreeNode* root) {
//         TreeNode* node=root;
//         preorder(node);
//         for(int i=1;i<arr.size();i++){
//             // TreeNode*mover=new TreeNode(arr[i]);
//             node->right=arr[i];
//             node->left=nullptr;
//             node=node->right;
//         }
        
//     }
// };