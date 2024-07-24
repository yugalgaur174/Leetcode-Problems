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
    ListNode* sortList(ListNode* head) {
        vector<int> ans;
        ListNode* mover=head;
        while(mover){
            ans.push_back(mover->val);
            mover=mover->next;
        }
        sort(ans.begin(),ans.end());
        mover=head;
        int i=0;
        while(mover){
            mover->val=ans[i];
            mover=mover->next;
            i++;
        }
        return head;
    }
};