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
    vector<vector<int>> arr;
    void make(TreeNode* node, int level){
        if(node==nullptr)return ;

        if(arr.size()==level){
            vector<int> a;
            a.push_back(node->val);
            arr.push_back(a);
        }
        else{
            arr[level].push_back(node->val);
        }
        make(node->left, level+1);
        make(node->right, level+1);

    }
    int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> v;
	    int n=nums.size();
	    for(int i=0;i<n;i++)
	    {
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int swaps=0;
	    for(int i=0;i<n;i++)
	    {
	        if(v[i].second==i) continue;
	        else {
	            swaps++;
	            swap(v[i],v[v[i].second]);
	            i--;
	        }
	    }
	    return swaps;
	}
    int minimumOperations(TreeNode* root) {
        // vector<int> a;
        make(root,0);
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[i].size();j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=1;i<arr.size();i++){
            ans+=minSwaps(arr[i]);
        }
        return ans;
    }
};