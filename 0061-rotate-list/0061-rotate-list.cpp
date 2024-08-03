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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL) return head;
        int n=0;
        ListNode* mover=head;
        while(mover){
            n++;
            mover=mover->next;
        }
        int m=k%n;
        int z=n-m;
        ListNode*mover2=head;
        if(m==0){
            return head;
        }
        else{
            mover=head;
            z--;
            while(z>0){
                z--;
                mover=mover->next;
            }
            ListNode*mover3=mover->next;
            ListNode *head1=mover3;
            mover->next=NULL;
            while(mover3->next){
                mover3=mover3->next;
            }
            mover3->next=head;
            head=head1;
        }
        return head;
    }
};