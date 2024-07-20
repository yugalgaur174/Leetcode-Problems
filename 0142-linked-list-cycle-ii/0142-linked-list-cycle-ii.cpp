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
    ListNode *detectCycle(ListNode *head) {
        ListNode*mover=head;
        if(head==NULL) return 0;
        if(head->next==NULL) return 0;
        unordered_map<ListNode*,int> mpp;
        // ListNode* slow=head;
        // ListNode* fast=head;
        // while(fast &&fast->next){
        //     slow=slow->next;
        //     fast=fast->next->next;
        //     if(slow==fast){
        //         return slow;

        //     }
        // }
        
        while(mover){

            if(mpp[mover]==0){
                mpp[mover]=1;
            }
            // else if(mpp[mover]==-1){
            //     return mover;
            // }
            else{
                return mover;
            }
            mover=mover->next;
        }
        return 0;
    }
};