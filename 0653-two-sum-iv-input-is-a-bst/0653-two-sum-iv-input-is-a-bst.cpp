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
    private:
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;

    void pushAll1(TreeNode* node){
        while(node){
            st1.push(node);
            node=node->left;
        }
    }
    void pushAll2(TreeNode* node){
        while(node){
            st2.push(node);

            node=node->right;
        }
    }
public:
    int next1(){
        TreeNode* node=st1.top();
        st1.pop();
        if(node->right){
            pushAll1(node->right);
        }
        return node->val;
    }
    int next2(){
        TreeNode* node=st2.top();
        st2.pop();
        if(node->left){
            pushAll2(node->left);
        }
        return node->val;
    }
    bool hasnext1(){
        return !st1.empty();
    }
    bool hasnext2(){
        return !st2.empty();
    }
    bool findTarget(TreeNode* root, int k) {
        if(root==nullptr) return false;
        pushAll1(root);
        pushAll2(root);
        int a=next1();
        int b=next2();
        while(a<b  ){
            if(a+b==k) return true;
            else if(a+b>k){
                if(hasnext2()){
                    b=next2();
                }
                else{
                    return false;
                }
            }
            else {
                if(hasnext1()){
                   a= next1();
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }
};