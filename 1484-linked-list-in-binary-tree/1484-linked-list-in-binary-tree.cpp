/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
vector<TreeNode*> a;
    // TreeNode* a=nullptr;
    void preorder(TreeNode* node,ListNode* head){
        if(node==nullptr) return;
        if(node->val==head->val) {
            a.push_back(node);
            // return;
        }
        preorder(node->left,head);
        preorder(node->right,head);

    }
    bool preordercheck(TreeNode* node,ListNode* head){
        if(node==nullptr && head==nullptr) return true;
        if(node==nullptr && head!=nullptr) return false;
        if(node!=nullptr && head==nullptr) return true;
        if(node->val!=head->val) return false;
        return preordercheck(node->left,head->next) || preordercheck(node->right,head->next);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(head==nullptr && root!=nullptr) return true;
        if(head!=nullptr && root==nullptr) return false;
        if(root==nullptr && head==nullptr) return true;
        preorder(root,head);
        if(a.size()==0)return false;
        for(int i=0;i<a.size();i++){
            if(preordercheck(a[i],head)==true){
                return true;
            }
        }
        return false;
    }
};