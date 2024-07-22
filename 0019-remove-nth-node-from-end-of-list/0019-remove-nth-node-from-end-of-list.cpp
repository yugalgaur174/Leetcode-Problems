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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return nullptr;
        if(head->next==NULL) return nullptr;
        ListNode* mover=head;
        ListNode* remove=head;
        ListNode* temp=head;
        int a=1,k=1;
        while(mover->next){
            temp=mover;
            mover=mover->next;
            k++;
        }
        if(k==n){
            head=head->next;
            return head;
        }
        mover=head;
        while(a<n){
            mover=mover->next;
            a++;
        }
        temp=remove;
        while(mover->next){
            temp=remove;
            mover=mover->next;
            remove=remove->next;
            
        }
        if(remove==NULL){
temp->next=NULL;
        
        }
        else{
            temp->next=remove->next;
        }
        return head;
    }
};