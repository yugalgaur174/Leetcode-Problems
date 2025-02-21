class FindElements {
public:
    TreeNode* tree;
    
    void setting(TreeNode* node){
        if(node->left){
            node->left->val = node->val * 2 + 1;
            setting(node->left);
        }
        if(node->right){
            node->right->val = node->val * 2 + 2;
            setting(node->right);
        }
    }
    
    FindElements(TreeNode* root) {
        root->val = 0;
        setting(root);
        tree = root;  
    }
    
    bool ans;
    
    void finding(TreeNode* t, int target){
        if(t == nullptr) return;
        if(t->val == target){
            ans = true;
            return; 
        }
        finding(t->left, target);
        finding(t->right, target);
    }

    bool find(int target) {
        ans = false;  
        finding(tree, target);
        return ans;
    }
};
