class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        int result = 0;
        dfs(root, distance, result);
        return result;
    }
private:
    vector<int> dfs(TreeNode* node, int distance, int& result) {
        if (!node) return {};
        if (!node->left && !node->right) return {1}; 
        vector<int> leftDistances = dfs(node->left, distance, result);
        vector<int> rightDistances = dfs(node->right, distance, result);
        for (int ld : leftDistances) {
            for (int rd : rightDistances) {
                if (ld + rd <= distance) {
                    result++;
                }
            }
        }
        vector<int> newDistances;
        for (int ld : leftDistances) {
            if (ld + 1 <= distance) {
                newDistances.push_back(ld + 1);
            }
        }
        for (int rd : rightDistances) {
            if (rd + 1 <= distance) {
                newDistances.push_back(rd + 1);
            }
        }
        return newDistances;
    }
};
TreeNode* buildTree(const vector<int>& values, int index = 0) {
    if (index >= values.size() || values[index] == -1) return nullptr;
    TreeNode* root = new TreeNode(values[index]);
    root->left = buildTree(values, 2 * index + 1);
    root->right = buildTree(values, 2 * index + 2);
    return root;
}
