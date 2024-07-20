/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL) return 0;
        if(head->next==NULL) return 0;

        unordered_map<ListNode*,int> mpp;
        ListNode* mover=head;
        while(mover){
            if(mpp[mover]==0){
                mpp[mover]=1;

            }
            else{
                return 1;
            }
            mover=mover->next;
        }
        return 0;
    }
};