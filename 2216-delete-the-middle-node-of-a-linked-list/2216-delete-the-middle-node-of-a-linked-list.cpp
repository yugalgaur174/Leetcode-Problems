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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL) return nullptr;
        if(head->next==NULL) return nullptr;
        ListNode* mover=head->next;
        ListNode* temp=head->next;
        ListNode* t=head;
        int k=0;
        while(mover->next){
            if(k==0){
                
                mover=mover->next;
                k=1;
            }
            else{
                
                mover=mover->next;
                temp=temp->next;
                t=t->next;
                k=0;
            }
        }
            if(t->next==NULL){
                return head;
            }
            else{
                t->next=t->next->next;
            }
            return head;
    }
};