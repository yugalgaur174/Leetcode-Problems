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
    ListNode* reverseList(ListNode* head) {
        ListNode* mover=head;
        ListNode* temp1=nullptr;
        // if(temp1->next==NULL){
        //     return temp1;
        // }
        ListNode* temp2=nullptr;
        while(mover!=NULL){
            temp2=mover->next;
            mover->next=temp1;
            temp1=mover;
            mover=temp2;

        }

        return temp1;

    }
};