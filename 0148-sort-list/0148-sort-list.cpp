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
   ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* dummy=new ListNode(0);
        ListNode* temp=dummy;

        while(l1&& l2){
            if(l1->val>l2->val){
                temp->next=l2;
                l2=l2->next;
            }
            else{
                temp->next=l1;
                l1=l1->next;
            }
            temp=temp->next;
        }
        while(l1){
            temp->next=l1;
                l1=l1->next;
            temp=temp->next;
        }
        while(l2){
            temp->next=l2;
                l2=l2->next;
            temp=temp->next;

        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr ||  head->next==nullptr) return head;
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* prev;
        while(fast && fast->next){
            prev=slow;
            fast=fast->next->next;
            slow=slow->next;
        }
        prev->next=nullptr;
        ListNode* l1= sortList(head);
        ListNode* l2=sortList(slow);
        return merge(l1,l2);

    }
};