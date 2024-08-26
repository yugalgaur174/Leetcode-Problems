/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }
        
        for (Node* child : root->children) {
            vector<int> childResult = postorder(child);
            result.insert(result.end(), childResult.begin(), childResult.end());
        }
        
        result.push_back(root->val);
        return result;
    }
};