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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> arr(m,vector<int>(n,-1));
        ListNode* mover=head;
        int left=0,top=0;
        int right=n-1,bottom=m-1;
        while(mover){
            for(int i=left;i<=right &&mover;i++){
                arr[top][i]=mover->val;
                mover=mover->next;
            }
            top++;
            for(int i=top;i<=bottom &&mover;i++){
                arr[i][right]=mover->val;
                mover=mover->next;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left &&mover;i--){
                    arr[bottom][i]=mover->val;
                    mover=mover->next;
                }
                bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top&&mover;i--){
                    arr[i][left]=mover->val;
                    mover=mover->next;
                }
                left++;
            }
        }
        return arr;
    }
};