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
    void deleteNode(ListNode* node) {
        ListNode * mover=node;
        while(mover->next!=NULL){
            ListNode* temp=mover;
            mover=mover->next;
            temp->val=mover->val;
            if(mover->next==NULL){
                temp->next=NULL;
            } 
        }
        // mover->next=NULL;
    }
};