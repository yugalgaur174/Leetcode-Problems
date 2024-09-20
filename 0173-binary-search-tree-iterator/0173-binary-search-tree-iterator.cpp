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
class BSTIterator {
private:
    vector<int> arr;
    int index;
    void inorder(TreeNode* node){
        if(node==nullptr)return;
        inorder(node->left);
        arr.push_back(node->val);
        inorder(node->right);
    }
public:
    BSTIterator(TreeNode* root) {
        index=0;
        inorder(root);
        
    }
    
    int next() {
        return arr[index++];
    }
    
    bool hasNext() {
        if(index>=arr.size()) return false;
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */