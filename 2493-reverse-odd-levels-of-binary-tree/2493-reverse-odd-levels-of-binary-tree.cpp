class Solution {
public:
    vector<vector<int>> arr;

    void check(TreeNode* root, int level) {
        if (root == nullptr) return;

        if (level % 2 == 1) { 
            int n = level / 2;
            if (n >= arr.size()) {
                arr.push_back({root->val});
            } else {
                arr[n].push_back(root->val);
            }
        }

        check(root->left, level + 1);
        check(root->right, level + 1);
    }

    void fill(TreeNode* root, int level) {
        if (root == nullptr) return;

        if (level % 2 == 1) { 
            int n = level / 2;
            root->val = arr[n].front();
            arr[n].erase(arr[n].begin());
        }

        fill(root->left, level + 1);
        fill(root->right, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        check(root, 0);

        for (auto& levelValues : arr) {
            reverse(levelValues.begin(), levelValues.end());
        }

        fill(root, 0);
        return root;
    }
};
